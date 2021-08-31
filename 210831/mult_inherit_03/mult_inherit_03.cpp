#include<iostream>

using namespace std;

// ���� ����� ��ȣ��

// LastDrived Ŭ������ ComplexFunc �Լ��� SimpleFunc(); -> ȣ�� ��� ��ȣ
// MiddleDrivedOne�� ��ӹ��� Base Ŭ������ SimpleFunc(); ����
// MiddleDrivedTwo�� ��ӹ��� Base Ŭ������ SimpleFunc(); ���� ��ȣ��

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

class MiddleDrivedTwo : virtual public Base		// ��ǥ -> ��� ����� �Ǵ� Ŭ���� ���� ����
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

class LastDrived : public MiddleDrivedOne, public MiddleDrivedTwo		// ��ǥ -> ��� ����� �Ǵ� Ŭ���� ���� ����
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