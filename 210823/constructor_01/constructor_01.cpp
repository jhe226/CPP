#include<iostream>

using namespace std;

// 생성자
// 1) 클래스 이름과 동일한 이름의 함수
// 2) 반환형 선언 X, 실제로 반환 X

class SimpleClass
{
	int num1;
	int num2;

public:
	// 생성자 : 객체 생성시 딱 한 번 호출됨 -> 멤버변수 초기화에 사용 가능
	// 생성자는 함수의 일종 -> 오버로딩 O, 디폴트 값 설정 가능

	SimpleClass()
	{
		num1 = 0;
		num2 = 0;
	}

	SimpleClass(int n)
	{
		num1 = n;
		num2 = 0;
	}

	SimpleClass(int n1, int n2)
	{
		num1 = n1;
		num2 = n2;
	}

	/*
	// 위의 세 함수를 한 줄로 정리 가능
	// 생성자도 함수의 디폴트 값 설정이 가능하다
	SimpleClass(int n1 = 0, int n2 = 0)
	{
		num1 = n1;
		num2 = n2;
	}
	*/

	void ShowData() const
	{
		cout << num1 << ' ' << num2 << endl;
	}
};

int main(void)
{
	// SimpleClass sc1(); -> 다른 의미.
	SimpleClass sc1;
	sc1.ShowData();

	// 아래는 사용 가능
	// SimleClass * ptr1 = newSimpleClass;
	// SimleClass * ptr1 = newSimpleClass();

	SimpleClass sc2(100);
	sc2.ShowData();

	SimpleClass sc3(100, 200);
	sc1.ShowData();

	return 0;
}