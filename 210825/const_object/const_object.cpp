#include<iostream>

using namespace std;

// const�� �Լ� �����ε�
class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{

	}

	SoSimple& Addnum(int n)
	{
		num += n;
		return *this;
	}

	// �Լ��� const ���� ������ �Լ� �����ε��� ����
	void SimpleFunc()
	{
		cout << "SimpleFunc : " << num << endl;
	}

	void SimpleFunc() const
	{
		cout << "const SimpleFunc : " << num << endl;
	}
};

// const ��ü �Ǵ� �����ڸ� ������� ����Լ� ȣ�� �� const ����� ����Լ��� ����ȴ�.
SoSimple YourFunc(const SoSimple& obj)
{
	obj.SimpleFunc();
}

int main()
{
	SoSimple obj1(2);
	const SoSimple obj2(7);
	
	obj1.SimpleFunc();
	obj2.SimpleFunc();


	YourFunc(obj1);		// const SimpleFunc : 2
	YourFunc(obj2);		// const SimpleFunc : 2

	return 0;

}