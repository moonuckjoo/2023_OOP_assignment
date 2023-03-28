#include <iostream>
using namespace std;

int det(int matrix[3][3]);
void cofactor(int matrix[3][3]);
void transpose(int matrix[3][3]);
void divide(int matrix[3][3]);
int main(void)
{

    int matrix[3][3]; // 2���� �迭 ����
    cout << "input a~i : ";
    for (int j = 0; j < 3; j++) // 2���� �迭�� ���� ��� A �����
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

int det(int matrix[3][3]) { // det(A) ���ϱ�
    int cir[3][3]; // ������ �迭
    int det = 0;// det��
    for (int j = 0; j < 3; j++) //��
    {
        for (int i = 0; i < 3; i++) //��
        {
            if (j == 0) //1���� ��
            {
                if (i == 0) //1���� ���
                {
                    cir[j][i] = matrix[j + 1][i + 1] * matrix[j + 2][i + 2] - matrix[j + 2][i + 1] * matrix[j + 1][i + 2];
                }
                else if (i == 1) //2���� ���
                {
                    cir[j][i] = -matrix[j + 1][i - 1] * matrix[j + 2][i + 1] + matrix[j + 1][i + 1] * matrix[j + 2][i - 1];
                }
                else if (i == 2) //3���� ���
                {
                    cir[j][i] = matrix[j + 1][i - 2] * matrix[j + 2][i - 1] - matrix[j + 1][i - 1] * matrix[j + 2][i - 2];
                }

            }
            else if (j == 1)//2���� ��
            {
                if (i == 0) //1���� ���
                {
                    cir[j][i] = -matrix[j - 1][i + 1] * matrix[j + 1][i + 2] + matrix[j + 1][i + 1] * matrix[j - 1][i + 2];
                }
                else if (i == 1) //2���� ���
                {
                    cir[j][i] = +matrix[j - 1][i - 1] * matrix[j + 1][i + 1] - matrix[j + 1][i - 1] * matrix[j - 1][i + 1];
                }
                else if (i == 2) //3���� ���
                {
                    cir[j][i] = -matrix[j - 1][i - 2] * matrix[j + 1][i - 1] + matrix[j + 1][i - 2] * matrix[j - 1][i - 1];
                }

            }
            else if (j == 2)//3���� ��
            {
                if (i == 0) //1���� ���
                {
                    cir[j][i] = matrix[j - 2][i + 1] * matrix[j - 1][i + 2] - matrix[j - 2][i + 2] * matrix[j - 1][i + 1];
                }
                else if (i == 1) //2���� ���
                {
                    cir[j][i] = -matrix[j - 2][i - 1] * matrix[j - 1][i + 1] + matrix[j - 2][i + 1] * matrix[j - 1][i - 1];
                }
                else if (i == 2) //3���� ���
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
void cofactor(int matrix[3][3]) { //cofactor �� ���ϱ�
    int cir[3][3]; // ������ �迭
    for (int j = 0; j < 3; j++) //��
    {
        for (int i = 0; i < 3; i++) //��
        {
            if (j == 0) //1���� ��
            {
                if (i == 0) //1���� ���
                {
                    cir[j][i] = matrix[j + 1][i + 1] * matrix[j + 2][i + 2] - matrix[j + 2][i + 1] * matrix[j + 1][i + 2];
                }
                else if (i == 1) //2���� ���
                {
                    cir[j][i] = -matrix[j + 1][i - 1] * matrix[j + 2][i + 1] + matrix[j + 1][i + 1] * matrix[j + 2][i - 1];
                }
                else if (i == 2) //3���� ���
                {
                    cir[j][i] = matrix[j + 1][i - 2] * matrix[j + 2][i - 1] - matrix[j + 1][i - 1] * matrix[j + 2][i - 2];
                }

            }
            else if (j == 1)//2���� ��
            {
                if (i == 0) //1���� ���
                {
                    cir[j][i] = -matrix[j - 1][i + 1] * matrix[j + 1][i + 2] + matrix[j + 1][i + 1] * matrix[j - 1][i + 2];
                }
                else if (i == 1) //2���� ���
                {
                    cir[j][i] = +matrix[j - 1][i - 1] * matrix[j + 1][i + 1] - matrix[j + 1][i - 1] * matrix[j - 1][i + 1];
                }
                else if (i == 2) //3���� ���
                {
                    cir[j][i] = -matrix[j - 1][i - 2] * matrix[j + 1][i - 1] + matrix[j + 1][i - 2] * matrix[j - 1][i - 1];
                }

            }
            else if (j == 2)//3���� ��
            {
                if (i == 0) //1���� ���
                {
                    cir[j][i] = matrix[j - 2][i + 1] * matrix[j - 1][i + 2] - matrix[j - 2][i + 2] * matrix[j - 1][i + 1];
                }
                else if (i == 1) //2���� ���
                {
                    cir[j][i] = -matrix[j - 2][i - 1] * matrix[j - 1][i + 1] + matrix[j - 2][i + 1] * matrix[j - 1][i - 1];
                }
                else if (i == 2) //3���� ���
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
void transpose(int matrix[3][3]) { // ����� y=-x�� ��Ī�Ͽ� ���
    int cir[3][3]; // ������ �迭
    for (int j = 0; j < 3; j++) //��
    {
        for (int i = 0; i < 3; i++) //��
        {
            if (j == 0) //1���� ��
            {
                if (i == 0) //1���� ���
                {
                    cir[j][i] = matrix[j + 1][i + 1] * matrix[j + 2][i + 2] - matrix[j + 2][i + 1] * matrix[j + 1][i + 2];
                }
                else if (i == 1) //2���� ���
                {
                    cir[j][i] = -matrix[j + 1][i - 1] * matrix[j + 2][i + 1] + matrix[j + 1][i + 1] * matrix[j + 2][i - 1];
                }
                else if (i == 2) //3���� ���
                {
                    cir[j][i] = matrix[j + 1][i - 2] * matrix[j + 2][i - 1] - matrix[j + 1][i - 1] * matrix[j + 2][i - 2];
                }

            }
            else if (j == 1)//2���� ��
            {
                if (i == 0) //1���� ���
                {
                    cir[j][i] = -matrix[j - 1][i + 1] * matrix[j + 1][i + 2] + matrix[j + 1][i + 1] * matrix[j - 1][i + 2];
                }
                else if (i == 1) //2���� ���
                {
                    cir[j][i] = +matrix[j - 1][i - 1] * matrix[j + 1][i + 1] - matrix[j + 1][i - 1] * matrix[j - 1][i + 1];
                }
                else if (i == 2) //3���� ���
                {
                    cir[j][i] = -matrix[j - 1][i - 2] * matrix[j + 1][i - 1] + matrix[j + 1][i - 2] * matrix[j - 1][i - 1];
                }

            }
            else if (j == 2)//3���� ��
            {
                if (i == 0) //1���� ���
                {
                    cir[j][i] = matrix[j - 2][i + 1] * matrix[j - 1][i + 2] - matrix[j - 2][i + 2] * matrix[j - 1][i + 1];
                }
                else if (i == 1) //2���� ���
                {
                    cir[j][i] = -matrix[j - 2][i - 1] * matrix[j - 1][i + 1] + matrix[j - 2][i + 1] * matrix[j - 1][i - 1];
                }
                else if (i == 2) //3���� ���
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
            cout << cir[j][i] << "   "; // ���� ����� ��Ī���� ���
            if (j == 2)
                cout << endl;
        }
    }
}

void divide(int matrix[3][3]) { // ����� 5�� ���� �� ���
    float cir[3][3]; // ������ �迭
    for (int j = 0; j < 3; j++) //��
    {
        for (int i = 0; i < 3; i++) //��
        {
            if (j == 0) //1���� ��
            {
                if (i == 0) //1���� ���
                {
                    cir[j][i] = matrix[j + 1][i + 1] * matrix[j + 2][i + 2] - matrix[j + 2][i + 1] * matrix[j + 1][i + 2];
                }
                else if (i == 1) //2���� ���
                {
                    cir[j][i] = -matrix[j + 1][i - 1] * matrix[j + 2][i + 1] + matrix[j + 1][i + 1] * matrix[j + 2][i - 1];
                }
                else if (i == 2) //3���� ���
                {
                    cir[j][i] = matrix[j + 1][i - 2] * matrix[j + 2][i - 1] - matrix[j + 1][i - 1] * matrix[j + 2][i - 2];
                }

            }
            else if (j == 1)//2���� ��
            {
                if (i == 0) //1���� ���
                {
                    cir[j][i] = -matrix[j - 1][i + 1] * matrix[j + 1][i + 2] + matrix[j + 1][i + 1] * matrix[j - 1][i + 2];
                }
                else if (i == 1) //2���� ���
                {
                    cir[j][i] = +matrix[j - 1][i - 1] * matrix[j + 1][i + 1] - matrix[j + 1][i - 1] * matrix[j - 1][i + 1];
                }
                else if (i == 2) //3���� ���
                {
                    cir[j][i] = -matrix[j - 1][i - 2] * matrix[j + 1][i - 1] + matrix[j + 1][i - 2] * matrix[j - 1][i - 1];
                }

            }
            else if (j == 2)//3���� ��
            {
                if (i == 0) //1���� ���
                {
                    cir[j][i] = matrix[j - 2][i + 1] * matrix[j - 1][i + 2] - matrix[j - 2][i + 2] * matrix[j - 1][i + 1];
                }
                else if (i == 1) //2���� ���
                {
                    cir[j][i] = -matrix[j - 2][i - 1] * matrix[j - 1][i + 1] + matrix[j - 2][i + 1] * matrix[j - 1][i - 1];
                }
                else if (i == 2) //3���� ���
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
            cout << cir[j][i] / 5 << "   "; // �� �迭�� 5�� ���� �� ���
            if (j == 2) //���� 3������ �ٹٲٱ�
                cout << endl;
        }
    }
}