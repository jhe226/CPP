#include<iostream>

using namespace std;

// this 포인터의 이해

class TwoNumber
{
private:
	int num1;
	int num2;

public:
	// 매개변수가 void형으로 선언되는 디폴트 생성자 -> 생성자가 하나도 정의되어있지 않을 때에만 삽입
	TwoNumber(int num1, int num2)
	{
		// this->num1은 멤버변수 num1 을 의미
		// 객체의 주소값으로 접근가능한 대상 -> 멤버변수 (지역변수X)
		// 매개변수 num1, num2를 통해 전달된 값-> 멤버변수 num1, num2에 저장
		// 범위가 좁은 변수가 우선권을 가짐
		// TwoNumber() = default;
		this->num1 = num1;
		this->num2 = num2;
	}
	/*
		멤버 이니셜라이저에서는 this 포인터 사용 불가.
		대신, 저장하는 변수 : 멤버변수 -> 저장되는 값(소괄호 안의 변수)은 매개 변수로 인식
		앞에 있는 변수 : 지역변수, 소괄호 안에 있는 변수 : 멤버변수 
		TwoNumber(int num1, int num2)
			: num1(num1), num2(num2)
		{
			// empty
		}
	*/

	void ShowTwoNumber()
	{
		// this 포인터를 사용 -> 멤버 변수에 접근함을 명확히함
		// 그러나 일반적으로 이러한 경우에는 this 포인터 생략
		cout << this->num1 << endl;
		cout << this->num2 << endl;
	}
};

int main()
{
	TwoNumber(2, 3);
}