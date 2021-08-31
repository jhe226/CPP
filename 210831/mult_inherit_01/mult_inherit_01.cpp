#include<iostream>

using namespace std;

// ���� ����� �⺻ ���
// ���� ��� : �� �̻��� Ŭ������ ����ϴ� ����
// ���� Ŭ������ ��ü�� ��� ���� Ŭ������ ����� ����

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

class MultiDrived : public BaseOne, protected BaseTwo		// ��ǥ -> ��� ����� �Ǵ� Ŭ���� ���� ����
{
public:
	void ComplexFuc()
	{
		SimpleFuncOne();	// BaseOne�� ��� �Լ�
		SimpleFuncTwo();	// BaseTwo�� ��� �Լ�
	}
};

int main()
{
	MultiDrived mdr;
	mdr.ComplexFuc();
	return 0;
}