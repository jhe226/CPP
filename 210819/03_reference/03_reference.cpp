#include<iostream>

using namespace std;

// 참조자(Reference) : 기존에 선언된 변수에 붙이는 '별칭'
// 자신이 참조하는 변수를 대신할 수 있는 또 하나의 이름
// 참조자가 만들어지면 변수의 이름과 다를 바 없음
// 참조자의 수에는 제한이 없으며, 참조자를 대상으로 참조자 생성도 가능

// & 연산자 : 이미 선언된 변수 앞에 오는 경우, 주소값 반환 명령
//			 새로 선언되는 변수 앞에 오는 경우, 참조자 선언


int main()
{
	int num1 = 1020;
	int &num2 = num1;

	num2 = 3047;
	cout << "Val : " << num1 << endl;
	cout << "Ref : " << num2 << endl;

	cout << "Val : " << &num1 << endl;
	cout << "Ref : " << &num2 << endl;

	return 0;
}