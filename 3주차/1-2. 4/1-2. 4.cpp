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
    FILE* fp = 0; // ����������
    uint8_t** input_image = 0; // ���������� ���� 
    uint8_t** output_image = 0;
    int x = 0;
    int y = 0;
    int a = 0;
    int b = 0;

    // Load input image
    cout << "Input file name: ";
    cin >> inputname;
    if(strcmp(inputname,"barbara_512x512.raw")==0)
      fopen_s(&fp, IMAGE_NAME, "rb"); // �б���� ���� ����
    if (fp == 0) // ����ó�� ������ ������ ���� ���
    {
        cout << "Failed to open filename(" << IMAGE_NAME << ")" << endl;
        return -1;
    }

    input_image = memory_alloc2D(IMAGE_HEIGHT, IMAGE_WIDTH); // �����Ҵ� ����
    if (input_image == 0) // �����Ҵ� ����!
    {
        cout << "Failed to allocate memory" << endl;
        return -1;
    }
    for (int i = 0; i < IMAGE_HEIGHT; i++)
        fread(input_image[i], sizeof(uint8_t), IMAGE_WIDTH, fp); //ù ��ǥ�� ����. ��������길ŭ �ʺ��� �� FP�� �ִ� ���� �ֱ�
    fclose(fp);

    cout << "1st coordinate : ";
    cin >> x;
    cin.ignore(5, ','); // �޸� �Է� ����
    cin >> y;
    cout << "2nd coordinate : ";
    cin >> a;
    cin.ignore(5, ','); // �޸� �Է� ����
    cin >> b;

    if (x > a && y > b) // ũ�Ⱑ �ݴ�� x��ǥ�� �ٲٱ�
    {
        swap(x, a);
        swap(y, b);
    }
    else if (x > a && y < b) //ũ�Ⱑ �ݴ�� y��ǥ�� �ٲٱ�
    {
        swap(x, a);
    }
    else if (x<a && y>b)
    {
        swap(y, b);
    }
    output_image = memory_alloc2D(IMAGE_HEIGHT, IMAGE_WIDTH); // �̹����� ó���ؼ� ������ �迭�� �����Ҵ�

    if (output_image == 0) // �����Ҵ� ����
    {
        cout << "Failed to allocate memory" << endl;
        return -1;
    }


    for (int i = 0; i < b - y; i++) //cropped�ؼ� ���� ����
    {
        for (int j = 0; j < a - x; j++)
        {
            output_image[i][j] = input_image[i + y][j + x];
        }
    }

    fopen_s(&fp, RESULT_NAME, "wb"); //������� ���� ����
    if (fp == 0) // ���� ���� ����
    {
        cout << "Failed to open filename(" << RESULT_NAME << ")" << endl;
        return -1;
    }
    for (int i = 0; i < b - y; i++)
    {
        fwrite(output_image[i], sizeof(uint8_t), (size_t)(a - x), fp); //���� �� ���
    }
    fclose(fp); //���ϴݱ�

    //�¿����

    for (int i = 0; i < IMAGE_HEIGHT; i++)  // �¿�������� �̹��� �迭�� ����
    {
        for (int j = 0; j < IMAGE_WIDTH; j++)
        {
            output_image[i][j] = input_image[i][IMAGE_WIDTH - j];
        }
    }

    fopen_s(&fp, RESULT_NAME2, "wb"); //������� ���� ����

    if (fp == 0) // ���� ���� ����
    {
        cout << "Failed to open filename(" << RESULT_NAME2 << ")" << endl;
        return -1;
    }
    for (int i = 0; i < IMAGE_HEIGHT; i++)
    {
        fwrite(output_image[i], sizeof(uint8_t), (size_t)(IMAGE_WIDTH), fp); //���� �� ���
    }
    fclose(fp);//���ϴݱ�


    //���Ϲ���

    for (int i = 0; i < IMAGE_HEIGHT; i++)  //���� �������� �̹����迭�� ����
    {
        for (int j = 0; j < IMAGE_WIDTH; j++)
        {
            output_image[i][j] = input_image[IMAGE_HEIGHT - 1 - i][j];
        }
    }

    fopen_s(&fp, RESULT_NAME3, "wb"); //������� ���� ����

    if (fp == 0) // ���� ���� ����
    {
        cout << "Failed to open filename(" << RESULT_NAME3 << ")" << endl;
        return -1;
    }
    for (int i = 0; i < IMAGE_HEIGHT; i++)
    {
        fwrite(output_image[i], sizeof(uint8_t), (size_t)(IMAGE_WIDTH), fp); //���� �� ���
    }
    fclose(fp);//���ϴݱ�

    memory_free2D(output_image); // �����Ҵ� ����
    memory_free2D(input_image); // �����Ҵ� ����

    return 0;
}


uint8_t** memory_alloc2D(size_t height, size_t width) // �����Ҵ� �Լ�
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

int memory_free2D(uint8_t** memory) // �����Ҵ� ���� �Լ�
{
    if (memory == 0)
        return -1;
    if (memory[0])
        delete[] memory[0];

    delete[] memory;
    return 0;
}