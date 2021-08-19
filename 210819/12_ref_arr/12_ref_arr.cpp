#include<iostream>

using namespace std;

// 참조자의 선언 가능 범위
// 참조자는 선언과 동시에 누군가를 참조해야하는데, 그 대상은 기본적으로 변수가 되어야 함
// 참조자 : 참조대상 변경 불가

int main()
{
	int arr[3] = { 1, 3, 5 };
	// 변수의 성향을 지니는 대상 -> 참조자 선언 O
	// 배열의 요소 역시 변수 성향 -> 참조자 선언 O
	int &ref1 = arr[0];
	int &ref2 = arr[1];
	int &ref3 = arr[2];

	cout << ref1 << endl;
	cout << ref2 << endl;
	cout << ref3 << endl;

	// int &ref3 = arr[0]; -> 빌드 오류 : 참조자는 참조 대상 변경 X
	// 오류 내용 : 재정의, 여러 번 초기화하였습니다.

	return 0;
}