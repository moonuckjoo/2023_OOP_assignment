#define _CRT_SECURE_NO_WARNNINGS
#include <iostream>
#include <cmath>
using namespace std;

#define PI acos(-1) // ���Լ��� �̿��Ͽ� ���� ����

int main()
{
	double result=0;
	int n1, n2, n3;
	double rad=0;
	cout << "Degree: ";
	cin >> n1;
	rad = n1 * PI/ 180; // �Է¹��� ���ڸ� ȣ������ �̿��Ͽ� ���� ������ ��ȯ
	double	T[3][3] = { 
		{-cos(rad),sin(rad),0}
		,{sin(rad),cos(rad),0}
		,{0,0,}
	};
	cout << "Coordinate: ";
	cin >> n1 >> n2 >> n3;
	int input[3] = { n1,n2,n3 };
	for (int i = 0; i < 3; i++)
	{
		result = 0;
		for (int j = 0; j < 3; j++)
			result += input[j] * T[j][i];
			cout << (int)result<<" ";
	}

}