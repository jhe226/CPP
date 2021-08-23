#include<iostream>

using namespace std;

// private ������ : AAA Ŭ������ ��� �Լ� �������� AAA Ŭ������ ��ü ���� ����
// AAA Ŭ������ ��� �Լ� �������� AAA Ŭ������ ��ü ���� ����
// �����ڰ� private -> �ܺο����� ��ü ���� ���X

class AAA
{
private:
	int num;
public:
	AAA() : num(0) {}
	AAA& CreateInitObj(int n) const
	{
		AAA* ptr = new AAA(n);	// Ŭ���� ���� -> private ������ ȣ�� ����
		return *ptr;
	}
	void ShowNum() const { cout << num << endl; }

private:
	// �����ڰ� private -> Ŭ���� �ܺο����� �� �������� ȣ���� ���� ��ü ���� �Ұ�
	AAA(int n) : num(n) {}
};

int main()
{
	// AAA base(1); -> �Ұ�(������ private)
	AAA base;
	base.ShowNum();

	AAA& obj1 = base.CreateInitObj(3);
	obj1.ShowNum();

	AAA& obj2 = base.CreateInitObj(12);
	obj2.ShowNum();

	delete& obj1;
	delete& obj2;

	return 0;
}