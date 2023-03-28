#include <iostream>
#include <cmath>
using namespace std;
void Discriminant(float a, float b, float c); // 판별식을 함수로 만들자.
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
    if (a == 0) // 2차방정식의 조건이 성립되지 않을 때 프로그램 종료
    {
        cout << "Unexpected factor of a quadratic term";
        return 0;
    }
    else // 2차방정식이 완성됐을 때 
    {
        cout << "the roots of " << a << "x^2 +" << b << "x +" << c << "= 0 : " << endl << endl;
        Discriminant(a, b, c);
    }
    return 0;

}
void Discriminant(float a, float b, float c)
{
    if ((pow(b, 2) - 4 * a * c) < 0) //판별식이 0보다 작을 때(실근 존재 x)
    {
        cout << "The equation has no real number solutions";
    }
    else if ((pow(b, 2) - 4 * a * c) == 0) // 판별식이 0일 때(중근 존재)
    {
        cout << "X1, X2 = " << -b / 2 * a << " (double root)";
    }
    else // 판별식이 양수(서로 다른 실근 항상 존재)이고 분자가 뺄셈인 경우 유리화를 진행하면 뺄셈이 사라진다.
    {
        roots(a, b, c);
    }
}
void roots(float a, float b, float c)
{
    float x1 = 0;
    float x2 = 0;
    if (b > 0) //b>0인 경우 x2가 뺄셈처리
    {
        x2 = (-b - sqrt(b * b - 4 * a * c)) / 2 * a; // 뺄셈이 없어서 연산에러 x
        x1 = 2 * c / (b + sqrt(b * b - 4 * a * c)); //유리화 진행 후 계산
    }
    else if (b == 0) // b=0이어서 근의 공식에서 분자에 뺄셈이 없는 경우 
    {
        x1 = sqrt(c);
        x2 = -sqrt(c);
    }
    else  // b<0인 경우 x1이 뺄셈처리
    {
        x2 = 2 * c / (b - sqrt(b*b - 4 * a * c)); //유리화 진행 후 계산
        x1 = (-b + sqrt(b * b - 4 * a * c)) / 2 * a; // 뺄셈이 없어서 연산에러 x
    }
    cout << "X1 = " << x1 << ", X2 = " << x2;
}
