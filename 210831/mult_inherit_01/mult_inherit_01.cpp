#include<iostream>

using namespace std;

// 다중 상속의 기본 방법
// 다중 상속 : 둘 이상의 클래스를 상속하는 형태
// 유도 클래스의 객체는 모든 기초 클래스의 멤버를 포함

class BaseOne
{
public:
	void SimpleFuncOne()
	{
		cout << "BaseOne" << endl;
	}
};

class BaseTwo
{
public:
	void SimpleFuncTwo()
	{
		cout << "BaseTwo" << endl;
	}
};

class MultiDrived : public BaseOne, protected BaseTwo		// 쉼표 -> 상속 대상이 되는 클래스 구분 가능
{
public:
	void ComplexFuc()
	{
		SimpleFuncOne();	// BaseOne의 멤버 함수
		SimpleFuncTwo();	// BaseTwo의 멤버 함수
	}
};

int main()
{
	MultiDrived mdr;
	mdr.ComplexFuc();
	return 0;
}