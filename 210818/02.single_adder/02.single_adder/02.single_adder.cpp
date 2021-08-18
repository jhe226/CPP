#include<iostream>

// scanf를 대신하는 데이터의 입력
// 출력에서와 마찬가지로 입력에서도 별도의 서식 지정이 불필요함

int main() {

	// 입력의 기본 구성 std::cin >> '변수'
	// cin은 함수가 아닌 객체, >>은 입력 연산자

	int val1;
	std::cout << "첫 번째 숫자입력 : ";
	std::cin >> val1;

	int val2;
	std::cout << "두 번째 숫자입력 : ";
	std::cin >> val2;

	int result = val1 + val2;
	std::cout << "덧셈 결과 : " << result << std::endl;

	return 0;
}