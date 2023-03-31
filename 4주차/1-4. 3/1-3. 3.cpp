#define _CRT_SECURE_NO_WARNNINGS
#include <iostream>
#include <cmath>
using namespace std;
//진법 변환 함수들.
int change1(int number[100], int n1, int k); // 입력받은 숫자를 10진수로 변환
void change2(int a, int n2);// 10진수를 원하는 진수로 변환 단, 16진수 제외
void hexa(int a, int n2);// 16진수 변환
int main()
{
    int a = 0; //변환된 10진수
    int k = 0; //자리수 체크
    int n1, n2; //input값을 n1진법에서 n2진법으로 변환
    char input[100] = { '0' };
    int number[100] = { 0 };
    cin >> input >> n1 >> n2;
    for (int i = 0; input[i] != NULL; i++)
    {
        if (input[i] != '0')
            number[i] = input[i] - '0'; //아스키 코드를 이용하여 문자를 숫자로 변환
        if (input[i] >= 17 && input[i] <= 22) // 변환된 숫자가 10~15 사이인 경우 16진수라고 판단. 문자를 다시 숫자로 변환
            number[i] = input[i] - 7;
        k++; // 자리수 체크
    }
    a = change1(number, n1, k); //a값에 변환된 10진수 입력
    if (n2 != 16)
        change2(a, n2);
    else
        hexa(a, n2);

}
int change1(int number[100], int n1, int k) // 어떤 입력값이든 10진수로 변환
{
    int changenumber = 0;
    for (int i = 0; i < k; i++)
    {
        changenumber += number[i] * pow(n1, k - 1 - i);
    }
    return changenumber;
}
void change2(int a, int n2) //받은 값을 다시 저장
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
    if (a >= 10 && a <= 15) // 16진수인 경우
    {

        cout << static_cast<char>(a + 'A' - 10);
    }
    else
        cout << a;
}


