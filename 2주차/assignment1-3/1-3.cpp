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
    if (N1 > N2) // 함수에 들어가기 전에 숫자 내림차순 정렬
    {
        N3 = N1;
        N1 = N2;
        N2 = N3;
    }
    if (N1 == 0 || N1 == N2) // 예외 작은 숫자가 0이거나 숫자가 같은 경우
    {
        cout << "최대공약수 : " << N2; // 높은 숫자 출력
        cout << "최소공배수 : " << N1;
    }
    else
    {
        GCD(N1, N2); // 아닌 경우 GCD 출력
        cout << "최대공약수 : " << GCD(N1, N2) << endl;
        LCM(N1 * N2, GCD(N1, N2));//두 수의 곱을 최대공약수로 나누기 위해
    }
}
long long int GCD(long long int x, long long int y) { //유클리드 호제법을 통한 최대공약수 구하기
    if (y % x != 0)
        GCD(y % x, x);
    else
        return x;
}
void LCM(long long int x, long long int y) { //최대공약수를 이용해서 최소공배수 구하기
    cout << "최소공배수 : " << x / y << endl;
}