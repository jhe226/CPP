#include<iostream>

using namespace std;

// 다중 상속의 모호성

// LastDrived 클래스의 ComplexFunc 함수의 SimpleFunc(); -> 호출 대상 모호
// MiddleDrivedOne이 상속받은 Base 클래스의 SimpleFunc(); 인지
// MiddleDrivedTwo이 상속받은 Base 클래스의 SimpleFunc(); 인지 모호함

class Base
{
public:
	Base() { cout << "Base Constructor" << endl; }
	void SimpleFunc() { cout << "BaseOne" << endl; }
};

class MiddleDrivedOne : virtual public Base
{
public:
	MiddleDrivedOne() : Base()
	{
		cout << "MiddleDrivedOne Constructor" << endl;
	}
	void MiddleFuncOne()
	{
		SimpleFunc();
		cout << "MiddleDrivedOne" << endl;
	}
};

class MiddleDrivedTwo : virtual public Base		// 쉼표 -> 상속 대상이 되는 클래스 구분 가능
{
public:
	MiddleDrivedTwo() : Base()
	{
		cout << "MiddleDrivedTwo Constructor" << endl;
	}
	void MiddleFuncTwo()
	{
		SimpleFunc();
		cout << "MiddleDrivedTwo" << endl;
	}
};

class LastDrived : public MiddleDrivedOne, public MiddleDrivedTwo		// 쉼표 -> 상속 대상이 되는 클래스 구분 가능
{
public:
	LastDrived() : MiddleDrivedOne(), MiddleDrivedTwo()
	{
		cout << "LastDrived Constructor" << endl;
	}
	void ComplexFunc()
	{
		MiddleFuncOne();
		MiddleFuncTwo();
	}
};

int main()
{
	MultiDrived mdr;
	mdr.ComplexFuc();
	return 0;
}