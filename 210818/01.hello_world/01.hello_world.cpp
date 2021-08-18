#include<iostream>	// 헤더파일 선언

// C언어에서는 출력 대상에 따라 서식지정을 달리했으나
// C++에서는 해당 과정이 불필요하다.

int main() {
	
	// 출력 기본구성  std::cout<< '출력대상1' << '출력대상2' << '출력대상3';
	// cout : 함수X, 객체
	// << : 출력 연산자
	// std::endl출력 : 개행

	int num = 20;
	std::cout << "Hello World" << std::endl;
	std::cout << "Hello " << "World" << std::endl;
	std::cout << num << ' ' << 'A';
	std::cout << ' ' << 3.14 << std::endl;

	return 0;
}