#include<iostream>

using namespace std;

// 참조자를 이용한 Call-by-Reference

// 매개변수는 함수가 호출될 때 선언이 되는 변수 -> 함수 호출 과정에서 선언과 동시에 전달되는 대상으로 초기화
// 매개변수에 선언된 참조자는 선언과 동시에 초기화

void SwapRef2(int &ref1, int &ref2)
{
	// 참조자로 받는 경우 해당 메모리로 접근 가능 -> 스왑 가능

	int tmp = ref1;
	ref1 = ref2;
	ref2 = tmp;
}

int main()
{
	int val1 = 10;
	int val2 = 20;

	SwapRef2(val1, val2);
	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2 << endl;

	return 0;
}