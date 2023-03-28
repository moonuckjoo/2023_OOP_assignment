#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
const int IMAGE_HEIGHT = 512;
const int IMAGE_WIDTH = 512;
using namespace std;

uint8_t** memory_alloc2D(size_t height, size_t width);
int memory_free2D(uint8_t** memory);



int main()
{
    char inputname[30];
    const char* IMAGE_NAME = "Barbara_512x512.raw";
    const char* RESULT_NAME = "Barbara_512x512_cropped.raw";
    const char* RESULT_NAME2 = "Barbara_512x512_horizontalflip.raw";
    const char* RESULT_NAME3 = "Barbara_512x512_verticalflip.raw";
    FILE* fp = 0; // 파일포인터
    uint8_t** input_image = 0; // 이중포인터 선언 
    uint8_t** output_image = 0;
    int x = 0;
    int y = 0;
    int a = 0;
    int b = 0;

    // Load input image
    cout << "Input file name: ";
    cin >> inputname;
    if(strcmp(inputname,"barbara_512x512.raw")==0)
      fopen_s(&fp, IMAGE_NAME, "rb"); // 읽기모드로 파일 열기
    if (fp == 0) // 예외처리 파일이 열리지 않은 경우
    {
        cout << "Failed to open filename(" << IMAGE_NAME << ")" << endl;
        return -1;
    }

    input_image = memory_alloc2D(IMAGE_HEIGHT, IMAGE_WIDTH); // 동적할당 선언
    if (input_image == 0) // 동적할당 실패!
    {
        cout << "Failed to allocate memory" << endl;
        return -1;
    }
    for (int i = 0; i < IMAGE_HEIGHT; i++)
        fread(input_image[i], sizeof(uint8_t), IMAGE_WIDTH, fp); //첫 좌표가 시작. 사이즈오브만큼 너비설정 후 FP에 있는 파일 넣기
    fclose(fp);

    cout << "1st coordinate : ";
    cin >> x;
    cin.ignore(5, ','); // 콤마 입력 제외
    cin >> y;
    cout << "2nd coordinate : ";
    cin >> a;
    cin.ignore(5, ','); // 콤마 입력 제외
    cin >> b;

    if (x > a && y > b) // 크기가 반대면 x좌표를 바꾸기
    {
        swap(x, a);
        swap(y, b);
    }
    else if (x > a && y < b) //크기가 반대면 y좌표를 바꾸기
    {
        swap(x, a);
    }
    else if (x<a && y>b)
    {
        swap(y, b);
    }
    output_image = memory_alloc2D(IMAGE_HEIGHT, IMAGE_WIDTH); // 이미지를 처리해서 저장할 배열을 동적할당

    if (output_image == 0) // 동적할당 실패
    {
        cout << "Failed to allocate memory" << endl;
        return -1;
    }


    for (int i = 0; i < b - y; i++) //cropped해서 파일 복사
    {
        for (int j = 0; j < a - x; j++)
        {
            output_image[i][j] = input_image[i + y][j + x];
        }
    }

    fopen_s(&fp, RESULT_NAME, "wb"); //쓰기모드로 파일 열기
    if (fp == 0) // 파일 열기 실패
    {
        cout << "Failed to open filename(" << RESULT_NAME << ")" << endl;
        return -1;
    }
    for (int i = 0; i < b - y; i++)
    {
        fwrite(output_image[i], sizeof(uint8_t), (size_t)(a - x), fp); //생성 및 출력
    }
    fclose(fp); //파일닫기

    //좌우반전

    for (int i = 0; i < IMAGE_HEIGHT; i++)  // 좌우반전으로 이미지 배열을 복사
    {
        for (int j = 0; j < IMAGE_WIDTH; j++)
        {
            output_image[i][j] = input_image[i][IMAGE_WIDTH - j];
        }
    }

    fopen_s(&fp, RESULT_NAME2, "wb"); //쓰기모드로 파일 열기

    if (fp == 0) // 파일 열기 실패
    {
        cout << "Failed to open filename(" << RESULT_NAME2 << ")" << endl;
        return -1;
    }
    for (int i = 0; i < IMAGE_HEIGHT; i++)
    {
        fwrite(output_image[i], sizeof(uint8_t), (size_t)(IMAGE_WIDTH), fp); //생성 및 출력
    }
    fclose(fp);//파일닫기


    //상하반전

    for (int i = 0; i < IMAGE_HEIGHT; i++)  //상하 반전으로 이미지배열을 복사
    {
        for (int j = 0; j < IMAGE_WIDTH; j++)
        {
            output_image[i][j] = input_image[IMAGE_HEIGHT - 1 - i][j];
        }
    }

    fopen_s(&fp, RESULT_NAME3, "wb"); //쓰기모드로 파일 열기

    if (fp == 0) // 파일 열기 실패
    {
        cout << "Failed to open filename(" << RESULT_NAME3 << ")" << endl;
        return -1;
    }
    for (int i = 0; i < IMAGE_HEIGHT; i++)
    {
        fwrite(output_image[i], sizeof(uint8_t), (size_t)(IMAGE_WIDTH), fp); //생성 및 출력
    }
    fclose(fp);//파일닫기

    memory_free2D(output_image); // 동적할당 해제
    memory_free2D(input_image); // 동적할당 해제

    return 0;
}


uint8_t** memory_alloc2D(size_t height, size_t width) // 동적할당 함수
{
    uint8_t** memory = new uint8_t * [height];
    if (memory == 0)
        return 0;

    memory[0] = new uint8_t[height * width];
    if (memory[0] == 0)
    {
        delete[] memory;
        return 0;
    }

    for (size_t i = 1; i < height; i++)
        memory[i] = memory[i - 1] + width;

    return memory;
}

int memory_free2D(uint8_t** memory) // 동적할당 해제 함수
{
    if (memory == 0)
        return -1;
    if (memory[0])
        delete[] memory[0];

    delete[] memory;
    return 0;
}