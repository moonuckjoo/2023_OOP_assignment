#include <iostream>
#include <cstring>
using namespace std;

int cnt(int num[30], int k); //�ߺ����� �Լ�
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
    for (int i = 0; i < 15; i++) // num1 num2�� �Է¹��� arr�� int������ �Է�
    {
        if (arr1[i] - 48 < 15 && arr1[i] - 48 >= 0) //������ ���� ���� ���� ä���
            num[i] = arr1[i] - '0'; // arr1�� �տ������� ä���
        if (arr2[i] - 48 < 15 && arr2[i] - 48 >= 0) // ������ ���� ���� ���� ä���
            num[i + 15] = arr2[i] - '0'; // arr2�� 11��° �迭���� ä���
    }

    for (int i = 0; i < 30; i++) { // N���� �Է¹����� bucket[N]�� ���ڰ� 1�� ����
        if (num[i] < 10 && num[i] >= 0) //�Űܹ��� num�迭�� �� �ڸ� �� ������ ������� ����
            bucket[num[i]]++; // num�� �ڸ��� �ϳ��ϳ� ���ذ��鼭 ���� ����
    }

    cout << num[k] << bucket[num[k]]; //�� ó�� ���� ���

    for (k = 1; k < 30; k++) // �� ���ķ� ��Ģ �����ؼ� ���
    {
        if (num[k] < 10 && num[k] >= 0)//�Űܹ��� num�迭�� �� �ڸ� �� ������ ������� ����
        {
            if (cnt(num, k) == 0) // cnt�� 0���� ũ�� �ߺ�
                cout << num[k] << bucket[num[k]]; // �ߺ��� �ƴ϶�� ���
        }
    }

    return 0;
}
int cnt(int num[30], int k)// cnt�� 0���� ũ�� �ߺ�
{
    int cnt = 0;
    for (int j = k; j > 0; j--) //�ش� ���� ������ �� ���ڸ�����
    {
        if (num[k] == num[j - 1]) //���ڰ� �� �迭�� �ִٸ� �ݺ����� Ż���ؼ� ���x
        {
            cnt++; //cnt�� 1�� ����
        }
    }
    return cnt;
}