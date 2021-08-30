#include<iostream>
using namespace std;

// 함수 템블릿 : "함수를 만들어 낸다" -> 함수 기능은 결정되어 있지만 자료형은 결정되지 않아 결정해야함

// 1) <typename T> 대신 <class T> 사용해도 된다
// 2) T 대신 다른 문자 사용 가능

template <typename T>
T Add(T num1, T num2)	// 아래의 함수를 템플릿으로 정의
{
	return num1 + num2
}

int main()
{
	cout << Add<int>(15, 20) << endl;
	cout << Add<double>(2.9, 3.7) << endl;
	cout << Add<int>(3.2, 3.2) << endl;
	cout << Add<double>(3.14, 2.75) << endl;

	return 0;
}