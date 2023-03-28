#include <iostream>
#include <cmath>
using namespace std;
unsigned char matrix[384][767]; // ���������� ��ǥ ����
void fractal(int i, int length, int height); // ���ѱ��� �׸���
void print(int height, int length); // ����Ʈ�ϱ�
int main(void)
{
    unsigned char k;
    int N;
    int length; // �� ���� ����
    int num; // k�� ���ڷ� ġȯ
    int height; // �ﰢ���� ����
    cout << "input: ";
    cin >> k; // input�� �Է�
    num = k - 48; //char���� ���ڸ� �ƽ�Ű �ڵ带 ���� ���ڷ� ��ȯ
    N = pow(2, num - 1); // 3N�� �ﰢ���� ����
    length = 6 * N - 1; //�� ���� ����
    height = 3 * N; // �ﰢ���� ����

    for (int i = 0; i < height; i++) // �迭�� ���� �Է�
    {
        for (int j = 0; j < length; j++)
            matrix[i][j] = ' ';
    }
    fractal(height, height - 1 , 0); // ����Ż ������
    print(height, length); //�迭 ���
}

void print(int height, int length) { // �迭 ���
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}


void fractal(int i, int length, int height) //�Ʒ������� ����Ż���� ����
{
    if (i == 3) // ���� �� �ﰢ�� �׸���
    {
        matrix[height][length] = '$'; //ù ��° �� ����� ���
        matrix[height + 1][length - 1] = '$'; // �ι�° �� ���� ���
        matrix[height + 1][length + 1] = '$'; // �ι�° �� ������ ���
        for (int i = 0; i < 5; i++) // ����° �� ���
        {
            matrix[height + 2][length - 2 + i] = '$';
        }
        return;
    }
    fractal(i / 2, length, height); // ��� �ﰢ�� �׸���
    fractal(i / 2, length - (i / 2), height + (i / 2)); //���ʺκ� �׸���
    fractal(i / 2, length + (i / 2), height + (i / 2)); //������ �κ� �׸���
}