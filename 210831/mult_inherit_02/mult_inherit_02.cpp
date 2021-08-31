#include<iostream>

using namespace std;

// 다중 상속의 모호성

class BaseOne
{
public:
	void SimpleFunc()
	{
		cout << "BaseOne" << endl;
	}
};

class BaseTwo
{
public:
	void SimpleFunc()
	{
		cout << "BaseTwo" << endl;
	}
};

class MultiDrived : public BaseOne, protected BaseTwo		// 쉼표 -> 상속 대상이 되는 클래스 구분 가능
{
public:
	void ComplexFuc()
	{
		BaseOne::SimpleFunc();	// BaseOne의 멤버 함수
		BaseOne::SimpleFunc();	// BaseTwo의 멤버 함수
	}
};

int main()
{
	MultiDrived mdr;
	mdr.ComplexFuc();
	return 0;
}