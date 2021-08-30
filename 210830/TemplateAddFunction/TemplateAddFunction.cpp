#include<iostream>

using namespace std;

// 같은 이름의 템플릿 함수와 일반 함수가 같이 존재 가능

template <typename T>
T Add(T num1, T num2)	// 아래의 함수를 템플릿으로 정의
{
	cout << "Add(T num1, T num2)" << endl;
	return num1 + num2;
}

int Add(int num1, int num2)
{
	cout << "Add(int num1, int num2)" << endl;
	return num1 + num2;
}

double Add(double num1, double num2)
{
	cout << "Add(double num1, double num2)" << endl;
	return num1 + num2;
}

int main()
{
	// 일반 함수가 정의 X -> 템플릿 함수 호출
	// 일반 함수 정의 O -> 일반 함수 호출

	cout << Add(5, 7) << endl;
	cout << Add(3.7, 7.5) << endl;

	// 일반 함수 정의 -> <int>, <double> 표시를 통해 템플릿 함수 호출을 명시
	cout << Add<int>(5, 7) << endl;
	cout << Add<double>(3.7, 7.5) << endl;
	return 0;
}