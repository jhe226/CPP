#include<iostream>

using namespace std;

// ���� ����� ��ȣ��

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

class MultiDrived : public BaseOne, protected BaseTwo		// ��ǥ -> ��� ����� �Ǵ� Ŭ���� ���� ����
{
public:
	void ComplexFuc()
	{
		BaseOne::SimpleFunc();	// BaseOne�� ��� �Լ�
		BaseOne::SimpleFunc();	// BaseTwo�� ��� �Լ�
	}
};

int main()
{
	MultiDrived mdr;
	mdr.ComplexFuc();
	return 0;
}