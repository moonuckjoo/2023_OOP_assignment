#define _CRT_SECURE_NO_WARNNINGS
#include <iostream>
#include <cmath>
using namespace std;
//���� ��ȯ �Լ���.
int change1(int number[100], int n1, int k); // �Է¹��� ���ڸ� 10������ ��ȯ
void change2(int a, int n2);// 10������ ���ϴ� ������ ��ȯ ��, 16���� ����
void hexa(int a, int n2);// 16���� ��ȯ
int main()
{
    int a = 0; //��ȯ�� 10����
    int k = 0; //�ڸ��� üũ
    int n1, n2; //input���� n1�������� n2�������� ��ȯ
    char input[100] = { '0' };
    int number[100] = { 0 };
    cin >> input >> n1 >> n2;
    for (int i = 0; input[i] != NULL; i++)
    {
        if (input[i] != '0')
            number[i] = input[i] - '0'; //�ƽ�Ű �ڵ带 �̿��Ͽ� ���ڸ� ���ڷ� ��ȯ
        if (input[i] >= 17 && input[i] <= 22) // ��ȯ�� ���ڰ� 10~15 ������ ��� 16������� �Ǵ�. ���ڸ� �ٽ� ���ڷ� ��ȯ
            number[i] = input[i] - 7;
        k++; // �ڸ��� üũ
    }
    a = change1(number, n1, k); //a���� ��ȯ�� 10���� �Է�
    if (n2 != 16)
        change2(a, n2);
    else
        hexa(a, n2);

}
int change1(int number[100], int n1, int k) // � �Է°��̵� 10������ ��ȯ
{
    int changenumber = 0;
    for (int i = 0; i < k; i++)
    {
        changenumber += number[i] * pow(n1, k - 1 - i);
    }
    return changenumber;
}
void change2(int a, int n2) //���� ���� �ٽ� ����
{
    if (a == 0)
        return;
   
    change2(a / n2, n2);
    cout << a % n2;

}
void hexa(int a, int n2)
{
    if (a == 0)
        return;

    hexa(a / n2, n2);

    a%=n2;
    if (a >= 10 && a <= 15) // 16������ ���
    {

        cout << static_cast<char>(a + 'A' - 10);
    }
    else
        cout << a;
}


