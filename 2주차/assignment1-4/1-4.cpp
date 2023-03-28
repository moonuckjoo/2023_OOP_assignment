#include <iostream>
using namespace std;

int det(int matrix[3][3]);
void cofactor(int matrix[3][3]);
void transpose(int matrix[3][3]);
void divide(int matrix[3][3]);
int main(void)
{

    int matrix[3][3]; // 2차원 배열 생성
    cout << "input a~i : ";
    for (int j = 0; j < 3; j++) // 2차원 배열을 통해 행렬 A 만들기
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> matrix[j][i];
        }
    }
    cout << "Get and check determinant of the matrix" << endl << "det(A) = " << det(matrix) << endl;
    cout << endl << "Get the cofactor matrix C" << endl;
    cofactor(matrix);
    cout << endl << "Transpose the cofactor matrix C^T" << endl;
    transpose(matrix);
    cout << endl << "Divide each elements using determinant A^-1" << endl;;
    divide(matrix);
}

int det(int matrix[3][3]) { // det(A) 구하기
    int cir[3][3]; // 저장할 배열
    int det = 0;// det값
    for (int j = 0; j < 3; j++) //열
    {
        for (int i = 0; i < 3; i++) //행
        {
            if (j == 0) //1열일 때
            {
                if (i == 0) //1행인 경우
                {
                    cir[j][i] = matrix[j + 1][i + 1] * matrix[j + 2][i + 2] - matrix[j + 2][i + 1] * matrix[j + 1][i + 2];
                }
                else if (i == 1) //2행인 경우
                {
                    cir[j][i] = -matrix[j + 1][i - 1] * matrix[j + 2][i + 1] + matrix[j + 1][i + 1] * matrix[j + 2][i - 1];
                }
                else if (i == 2) //3행인 경우
                {
                    cir[j][i] = matrix[j + 1][i - 2] * matrix[j + 2][i - 1] - matrix[j + 1][i - 1] * matrix[j + 2][i - 2];
                }

            }
            else if (j == 1)//2열일 때
            {
                if (i == 0) //1행인 경우
                {
                    cir[j][i] = -matrix[j - 1][i + 1] * matrix[j + 1][i + 2] + matrix[j + 1][i + 1] * matrix[j - 1][i + 2];
                }
                else if (i == 1) //2행인 경우
                {
                    cir[j][i] = +matrix[j - 1][i - 1] * matrix[j + 1][i + 1] - matrix[j + 1][i - 1] * matrix[j - 1][i + 1];
                }
                else if (i == 2) //3행인 경우
                {
                    cir[j][i] = -matrix[j - 1][i - 2] * matrix[j + 1][i - 1] + matrix[j + 1][i - 2] * matrix[j - 1][i - 1];
                }

            }
            else if (j == 2)//3열일 때
            {
                if (i == 0) //1행인 경우
                {
                    cir[j][i] = matrix[j - 2][i + 1] * matrix[j - 1][i + 2] - matrix[j - 2][i + 2] * matrix[j - 1][i + 1];
                }
                else if (i == 1) //2행인 경우
                {
                    cir[j][i] = -matrix[j - 2][i - 1] * matrix[j - 1][i + 1] + matrix[j - 2][i + 1] * matrix[j - 1][i - 1];
                }
                else if (i == 2) //3행인 경우
                {
                    cir[j][i] = matrix[j - 2][i - 2] * matrix[j - 1][i - 1] - matrix[j - 2][i - 1] * matrix[j - 1][i - 2];
                }

            }
        }

    }
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            det += cir[i][j];
        }
    }
    return det;
}
void cofactor(int matrix[3][3]) { //cofactor 값 구하기
    int cir[3][3]; // 저장할 배열
    for (int j = 0; j < 3; j++) //열
    {
        for (int i = 0; i < 3; i++) //행
        {
            if (j == 0) //1열일 때
            {
                if (i == 0) //1행인 경우
                {
                    cir[j][i] = matrix[j + 1][i + 1] * matrix[j + 2][i + 2] - matrix[j + 2][i + 1] * matrix[j + 1][i + 2];
                }
                else if (i == 1) //2행인 경우
                {
                    cir[j][i] = -matrix[j + 1][i - 1] * matrix[j + 2][i + 1] + matrix[j + 1][i + 1] * matrix[j + 2][i - 1];
                }
                else if (i == 2) //3행인 경우
                {
                    cir[j][i] = matrix[j + 1][i - 2] * matrix[j + 2][i - 1] - matrix[j + 1][i - 1] * matrix[j + 2][i - 2];
                }

            }
            else if (j == 1)//2열일 때
            {
                if (i == 0) //1행인 경우
                {
                    cir[j][i] = -matrix[j - 1][i + 1] * matrix[j + 1][i + 2] + matrix[j + 1][i + 1] * matrix[j - 1][i + 2];
                }
                else if (i == 1) //2행인 경우
                {
                    cir[j][i] = +matrix[j - 1][i - 1] * matrix[j + 1][i + 1] - matrix[j + 1][i - 1] * matrix[j - 1][i + 1];
                }
                else if (i == 2) //3행인 경우
                {
                    cir[j][i] = -matrix[j - 1][i - 2] * matrix[j + 1][i - 1] + matrix[j + 1][i - 2] * matrix[j - 1][i - 1];
                }

            }
            else if (j == 2)//3열일 때
            {
                if (i == 0) //1행인 경우
                {
                    cir[j][i] = matrix[j - 2][i + 1] * matrix[j - 1][i + 2] - matrix[j - 2][i + 2] * matrix[j - 1][i + 1];
                }
                else if (i == 1) //2행인 경우
                {
                    cir[j][i] = -matrix[j - 2][i - 1] * matrix[j - 1][i + 1] + matrix[j - 2][i + 1] * matrix[j - 1][i - 1];
                }
                else if (i == 2) //3행인 경우
                {
                    cir[j][i] = matrix[j - 2][i - 2] * matrix[j - 1][i - 1] - matrix[j - 2][i - 1] * matrix[j - 1][i - 2];
                }

            }
        }

    }
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            cout << cir[i][j] << "   ";
            if (j == 2)
                cout << endl;
        }
    }
}
void transpose(int matrix[3][3]) { // 행렬을 y=-x에 대칭하여 출력
    int cir[3][3]; // 저장할 배열
    for (int j = 0; j < 3; j++) //열
    {
        for (int i = 0; i < 3; i++) //행
        {
            if (j == 0) //1열일 때
            {
                if (i == 0) //1행인 경우
                {
                    cir[j][i] = matrix[j + 1][i + 1] * matrix[j + 2][i + 2] - matrix[j + 2][i + 1] * matrix[j + 1][i + 2];
                }
                else if (i == 1) //2행인 경우
                {
                    cir[j][i] = -matrix[j + 1][i - 1] * matrix[j + 2][i + 1] + matrix[j + 1][i + 1] * matrix[j + 2][i - 1];
                }
                else if (i == 2) //3행인 경우
                {
                    cir[j][i] = matrix[j + 1][i - 2] * matrix[j + 2][i - 1] - matrix[j + 1][i - 1] * matrix[j + 2][i - 2];
                }

            }
            else if (j == 1)//2열일 때
            {
                if (i == 0) //1행인 경우
                {
                    cir[j][i] = -matrix[j - 1][i + 1] * matrix[j + 1][i + 2] + matrix[j + 1][i + 1] * matrix[j - 1][i + 2];
                }
                else if (i == 1) //2행인 경우
                {
                    cir[j][i] = +matrix[j - 1][i - 1] * matrix[j + 1][i + 1] - matrix[j + 1][i - 1] * matrix[j - 1][i + 1];
                }
                else if (i == 2) //3행인 경우
                {
                    cir[j][i] = -matrix[j - 1][i - 2] * matrix[j + 1][i - 1] + matrix[j + 1][i - 2] * matrix[j - 1][i - 1];
                }

            }
            else if (j == 2)//3열일 때
            {
                if (i == 0) //1행인 경우
                {
                    cir[j][i] = matrix[j - 2][i + 1] * matrix[j - 1][i + 2] - matrix[j - 2][i + 2] * matrix[j - 1][i + 1];
                }
                else if (i == 1) //2행인 경우
                {
                    cir[j][i] = -matrix[j - 2][i - 1] * matrix[j - 1][i + 1] + matrix[j - 2][i + 1] * matrix[j - 1][i - 1];
                }
                else if (i == 2) //3행인 경우
                {
                    cir[j][i] = matrix[j - 2][i - 2] * matrix[j - 1][i - 1] - matrix[j - 2][i - 1] * matrix[j - 1][i - 2];
                }

            }
        }

    }
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            cout << cir[j][i] << "   "; // 순서 뒤집어서 대칭으로 출력
            if (j == 2)
                cout << endl;
        }
    }
}

void divide(int matrix[3][3]) { // 행렬을 5로 나눈 값 출력
    float cir[3][3]; // 저장할 배열
    for (int j = 0; j < 3; j++) //열
    {
        for (int i = 0; i < 3; i++) //행
        {
            if (j == 0) //1열일 때
            {
                if (i == 0) //1행인 경우
                {
                    cir[j][i] = matrix[j + 1][i + 1] * matrix[j + 2][i + 2] - matrix[j + 2][i + 1] * matrix[j + 1][i + 2];
                }
                else if (i == 1) //2행인 경우
                {
                    cir[j][i] = -matrix[j + 1][i - 1] * matrix[j + 2][i + 1] + matrix[j + 1][i + 1] * matrix[j + 2][i - 1];
                }
                else if (i == 2) //3행인 경우
                {
                    cir[j][i] = matrix[j + 1][i - 2] * matrix[j + 2][i - 1] - matrix[j + 1][i - 1] * matrix[j + 2][i - 2];
                }

            }
            else if (j == 1)//2열일 때
            {
                if (i == 0) //1행인 경우
                {
                    cir[j][i] = -matrix[j - 1][i + 1] * matrix[j + 1][i + 2] + matrix[j + 1][i + 1] * matrix[j - 1][i + 2];
                }
                else if (i == 1) //2행인 경우
                {
                    cir[j][i] = +matrix[j - 1][i - 1] * matrix[j + 1][i + 1] - matrix[j + 1][i - 1] * matrix[j - 1][i + 1];
                }
                else if (i == 2) //3행인 경우
                {
                    cir[j][i] = -matrix[j - 1][i - 2] * matrix[j + 1][i - 1] + matrix[j + 1][i - 2] * matrix[j - 1][i - 1];
                }

            }
            else if (j == 2)//3열일 때
            {
                if (i == 0) //1행인 경우
                {
                    cir[j][i] = matrix[j - 2][i + 1] * matrix[j - 1][i + 2] - matrix[j - 2][i + 2] * matrix[j - 1][i + 1];
                }
                else if (i == 1) //2행인 경우
                {
                    cir[j][i] = -matrix[j - 2][i - 1] * matrix[j - 1][i + 1] + matrix[j - 2][i + 1] * matrix[j - 1][i - 1];
                }
                else if (i == 2) //3행인 경우
                {
                    cir[j][i] = matrix[j - 2][i - 2] * matrix[j - 1][i - 1] - matrix[j - 2][i - 1] * matrix[j - 1][i - 2];
                }

            }
        }

    }
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            cout << cir[j][i] / 5 << "   "; // 각 배열을 5로 나눈 값 출력
            if (j == 2) //숫자 3개마다 줄바꾸기
                cout << endl;
        }
    }
}