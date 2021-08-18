#include<iostream>

// 함수 오버로딩
/*
   C++은 함수 호출 시 '함수의 이름'과 '전달되는 인자의 정보'를 동시에 창조하여 호출할 함수를 결정함
   따라서 매개변수의 선언이 다르다면 동일한 이름의 함수도 정의 가능.
   또한 이러한 형태의 함수 정의를 가리켜 '함수 오버로딩(Function Overloading)'이라 한다.
*/

/*
   매개변수의 자료형, 매개변수의 수가 다르므로 오버로딩 성립.
   변환혀의 차이 -> 오버로딩 조건 만족 X
*/

void Myfunc()
{
	std::cout << "Myfunc(void) called" << std::endl;
}

void Myfunc(char c)		// 매개변수 자료형이 다름
{
	std::cout << "Myfunc(char c) called" << std::endl;
}

void Myfunc(int a)		// 매개변수 수가 다름
{
	std::cout << "Myfunc(int a) called" << std::endl;
}

void Myfunc(int a, int b)		// 매개변수 수가 다름
{
	std::cout << "Myfunc(int a, int b) called" << std::endl;
}

int main()
{
	Myfunc();
	Myfunc('A');
	Myfunc(12, 13);

	return 0;
}