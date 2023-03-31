#define _CRT_SECURE_NO_WARNNINGS
#include <iostream>
#include <cmath>
using namespace std;

#define PI acos(-1) // 역함수를 이용하여 파이 정의

int main()
{
	double result=0;
	int n1, n2, n3;
	double rad=0;
	cout << "Degree: ";
	cin >> n1;
	rad = n1 * PI/ 180; // 입력받은 숫자를 호도법을 이용하여 라디안 단위로 변환
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