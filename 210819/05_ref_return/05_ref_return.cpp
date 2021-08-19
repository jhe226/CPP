#include<iostream>

using namespace std;

// 반환형이 참조이고 반환도 참조로 받는 경우

int &RefRetFuncOne(int &ref)
{
	// 참조형으로 반환
	ref++;
	return ref;
}

int main(void)
{
	int num1 = 1;
	int &num2 = RefRetFuncOne(num1);	// 반환도 참조로 받음

	num1++;
	num2++;
	cout << "num1 : " << num1 << endl;
	cout << "num2 : " << num2 << endl;

	cout << "&num1 : " << &num1 << endl;
	cout << "&num2 : " << &num2 << endl;

	return 0;

}