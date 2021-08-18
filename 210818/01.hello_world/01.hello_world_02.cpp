#include<iostream>	

using namespace std;

int main() {

	// 출력 기본구성  std::cout<< '출력대상1' << '출력대상2' << '출력대상3';
	// cout : 함수X, 객체
	// << : 출력 연산자
	// std::endl출력 : 개행

	int num = 20;
	cout << "Hello World" << endl;
	cout << "Hello " << "World" << endl;
	cout << num << ' ' << 'A';
	cout << ' ' << 3.14 << endl;

	return 0;
}
