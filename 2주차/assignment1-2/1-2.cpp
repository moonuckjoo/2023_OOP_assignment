#include <iostream>
#include <cmath>
using namespace std;
void Discriminant(float a, float b, float c); // �Ǻ����� �Լ��� ������.
void roots(float a, float b, float c);
int main()
{
    float a, b, c;
    cout << "input a : ";
    cin >> a;
    cout << endl;
    cout << "input b : ";
    cin >> b;
    cout << endl;
    cout << "input c : ";
    cin >> c;
    cout << endl;
    if (a == 0) // 2���������� ������ �������� ���� �� ���α׷� ����
    {
        cout << "Unexpected factor of a quadratic term";
        return 0;
    }
    else // 2���������� �ϼ����� �� 
    {
        cout << "the roots of " << a << "x^2 +" << b << "x +" << c << "= 0 : " << endl << endl;
        Discriminant(a, b, c);
    }
    return 0;

}
void Discriminant(float a, float b, float c)
{
    if ((pow(b, 2) - 4 * a * c) < 0) //�Ǻ����� 0���� ���� ��(�Ǳ� ���� x)
    {
        cout << "The equation has no real number solutions";
    }
    else if ((pow(b, 2) - 4 * a * c) == 0) // �Ǻ����� 0�� ��(�߱� ����)
    {
        cout << "X1, X2 = " << -b / 2 * a << " (double root)";
    }
    else // �Ǻ����� ���(���� �ٸ� �Ǳ� �׻� ����)�̰� ���ڰ� ������ ��� ����ȭ�� �����ϸ� ������ �������.
    {
        roots(a, b, c);
    }
}
void roots(float a, float b, float c)
{
    float x1 = 0;
    float x2 = 0;
    if (b > 0) //b>0�� ��� x2�� ����ó��
    {
        x2 = (-b - sqrt(b * b - 4 * a * c)) / 2 * a; // ������ ��� ���꿡�� x
        x1 = 2 * c / (b + sqrt(b * b - 4 * a * c)); //����ȭ ���� �� ���
    }
    else if (b == 0) // b=0�̾ ���� ���Ŀ��� ���ڿ� ������ ���� ��� 
    {
        x1 = sqrt(c);
        x2 = -sqrt(c);
    }
    else  // b<0�� ��� x1�� ����ó��
    {
        x2 = 2 * c / (b - sqrt(b*b - 4 * a * c)); //����ȭ ���� �� ���
        x1 = (-b + sqrt(b * b - 4 * a * c)) / 2 * a; // ������ ��� ���꿡�� x
    }
    cout << "X1 = " << x1 << ", X2 = " << x2;
}
