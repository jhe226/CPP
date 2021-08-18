#include<iostream>

//  매개 변수에 설정하는 '디폴드 값'이 존재한다

int Adder(int num1 = 1, int num2 = 2)
{
	// 인자가 전달 되지 않으면 디폴트 값이 전달된 것으로 한다.
	return num1 + num2;
}

int main() {
	// 실행되는 함수만 보면 함수 원형이 오버로딩이 된건지,
	// 디폴트 값이 존재하는 건지 예상하기 힘들다.

	std::cout << Adder() << std::endl;		//  3 = 1 + 2
	std::cout << Adder(5) << std::endl;		// 7 = 5 + 2
	std::cout << Adder(3, 5) << std::endl;	// 8 = 3 + 5

	return 0;
}

// 가능하면 디폴트 값과 오버로딩을 함께 사용하지 않는다.