#include <iostream>
#include <cmath>
using namespace std;
unsigned char matrix[384][767]; // 전역변수로 좌표 생성
void fractal(int i, int length, int height); // 무한구조 그리기
void print(int height, int length); // 프린트하기
int main(void)
{
    unsigned char k;
    int N;
    int length; // 한 변의 길이
    int num; // k를 숫자로 치환
    int height; // 삼각형의 높이
    cout << "input: ";
    cin >> k; // input값 입력
    num = k - 48; //char형의 문자를 아스키 코드를 통해 숫자로 변환
    N = pow(2, num - 1); // 3N이 삼각형의 높이
    length = 6 * N - 1; //한 변의 길이
    height = 3 * N; // 삼각형의 높이

    for (int i = 0; i < height; i++) // 배열에 공백 입력
    {
        for (int j = 0; j < length; j++)
            matrix[i][j] = ' ';
    }
    fractal(height, height - 1 , 0); // 프랙탈 돌리기
    print(height, length); //배열 출력
}

void print(int height, int length) { // 배열 출력
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}


void fractal(int i, int length, int height) //아래서부터 프랙탈구조 형성
{
    if (i == 3) // 제일 위 삼각형 그리기
    {
        matrix[height][length] = '$'; //첫 번째 줄 가운데에 기록
        matrix[height + 1][length - 1] = '$'; // 두번째 줄 왼쪽 기록
        matrix[height + 1][length + 1] = '$'; // 두번째 줄 오른쪽 기록
        for (int i = 0; i < 5; i++) // 세번째 줄 기록
        {
            matrix[height + 2][length - 2 + i] = '$';
        }
        return;
    }
    fractal(i / 2, length, height); // 가운데 삼각형 그리기
    fractal(i / 2, length - (i / 2), height + (i / 2)); //왼쪽부분 그리기
    fractal(i / 2, length + (i / 2), height + (i / 2)); //오른쪽 부분 그리기
}