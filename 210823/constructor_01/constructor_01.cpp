#include<iostream>

using namespace std;

// ������
// 1) Ŭ���� �̸��� ������ �̸��� �Լ�
// 2) ��ȯ�� ���� X, ������ ��ȯ X

class SimpleClass
{
	int num1;
	int num2;

public:
	// ������ : ��ü ������ �� �� �� ȣ��� -> ������� �ʱ�ȭ�� ��� ����
	// �����ڴ� �Լ��� ���� -> �����ε� O, ����Ʈ �� ���� ����

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
	// ���� �� �Լ��� �� �ٷ� ���� ����
	// �����ڵ� �Լ��� ����Ʈ �� ������ �����ϴ�
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
	// SimpleClass sc1(); -> �ٸ� �ǹ�.
	SimpleClass sc1;
	sc1.ShowData();

	// �Ʒ��� ��� ����
	// SimleClass * ptr1 = newSimpleClass;
	// SimleClass * ptr1 = newSimpleClass();

	SimpleClass sc2(100);
	sc2.ShowData();

	SimpleClass sc3(100, 200);
	sc1.ShowData();

	return 0;
}