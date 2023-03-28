#include <iostream>
#include <cstring>
using namespace std;

int cnt(int num[30], int k); //중복방지 함수
int main(void) {
    int num[30];
    int k = 0;
    char arr1[15];
    int bucket[10] = { 0 };
    char arr2[15];
    cout << "input num1 : " << endl;
    cin >> arr1;
    cout << "input num2 : " << endl;
    cin >> arr2;
    for (int i = 0; i < 15; i++) // num1 num2에 입력받은 arr을 int형으로 입력
    {
        if (arr1[i] - 48 < 15 && arr1[i] - 48 >= 0) //쓰레기 값이 없을 때만 채우기
            num[i] = arr1[i] - '0'; // arr1은 앞에서부터 채우기
        if (arr2[i] - 48 < 15 && arr2[i] - 48 >= 0) // 쓰레기 값이 없을 때만 채우기
            num[i + 15] = arr2[i] - '0'; // arr2는 11번째 배열부터 채우기
    }

    for (int i = 0; i < 30; i++) { // N값을 입력받으면 bucket[N]의 숫자가 1씩 증가
        if (num[i] < 10 && num[i] >= 0) //옮겨받은 num배열에 한 자리 수 정수가 담겨있을 때만
            bucket[num[i]]++; // num에 자리수 하나하나 비교해가면서 숫자 증가
    }

    cout << num[k] << bucket[num[k]]; //맨 처음 숫자 출력

    for (k = 1; k < 30; k++) // 그 이후로 규칙 적용해서 출력
    {
        if (num[k] < 10 && num[k] >= 0)//옮겨받은 num배열에 한 자리 수 정수가 담겨있을 때만
        {
            if (cnt(num, k) == 0) // cnt가 0보다 크면 중복
                cout << num[k] << bucket[num[k]]; // 중복이 아니라면 출력
        }
    }

    return 0;
}
int cnt(int num[30], int k)// cnt가 0보다 크면 중복
{
    int cnt = 0;
    for (int j = k; j > 0; j--) //해당 숫자 전부터 맨 앞자리까지
    {
        if (num[k] == num[j - 1]) //숫자가 앞 배열에 있다면 반복문을 탈출해서 출력x
        {
            cnt++; //cnt값 1씩 증가
        }
    }
    return cnt;
}