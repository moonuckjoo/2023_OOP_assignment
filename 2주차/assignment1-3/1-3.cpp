#include <iostream>
using namespace std;
void LCM(long long int x, long long int y);
long long int GCD(long long int x, long long int y);
int main(void)
{
    long long int N1, N2, N3;
    cout << "input N1 :";
    cin >> N1;
    cout << "input N2 :";
    cin >> N2;
    if (N1 > N2) // �Լ��� ���� ���� ���� �������� ����
    {
        N3 = N1;
        N1 = N2;
        N2 = N3;
    }
    if (N1 == 0 || N1 == N2) // ���� ���� ���ڰ� 0�̰ų� ���ڰ� ���� ���
    {
        cout << "�ִ����� : " << N2; // ���� ���� ���
        cout << "�ּҰ���� : " << N1;
    }
    else
    {
        GCD(N1, N2); // �ƴ� ��� GCD ���
        cout << "�ִ����� : " << GCD(N1, N2) << endl;
        LCM(N1 * N2, GCD(N1, N2));//�� ���� ���� �ִ������� ������ ����
    }
}
long long int GCD(long long int x, long long int y) { //��Ŭ���� ȣ������ ���� �ִ����� ���ϱ�
    if (y % x != 0)
        GCD(y % x, x);
    else
        return x;
}
void LCM(long long int x, long long int y) { //�ִ������� �̿��ؼ� �ּҰ���� ���ϱ�
    cout << "�ּҰ���� : " << x / y << endl;
}