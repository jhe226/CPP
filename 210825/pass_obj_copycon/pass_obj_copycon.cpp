#include<iostream>

using namespace std;

// ���� �����ڰ� ȣ��Ǵ� ����
// 1. ������ ������ ��ü�� �̿��ؼ� ���ο� ��ü�� �ʱ�ȭ �ϴ� ���
// 2. Call-by-Value ����� �Լ� ȣ�� �������� ��ü�� ���ڷ� �����ϴ� ���
// 3. ��ü�� ��ȯ�ϵ�, ���������� ��ȯ���� �ʴ� ���

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{

	}

	SoSimple(const SoSimple& copy) : num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple& copy)" << endl;
	}

	void ShowData()
	{
		cout << "num : " << num << endl;
	}
};

void SimpleFuncObj(SoSimple ob)		// ������ ����
{
	// void void SimpleFuncObj(SoSimple& ob)	// ������ ����

	// ���� ���� �� ����� ���ÿ� �ʱ�ȭ
	ob.ShowData();
}

int main()
{
	SoSimple obj(7);
	cout << "�Լ� ȣ�� ��" << endl;
	// ��ü obj �� ���ڷ� ����
	SimpleFuncObj(obj);
	cout << "�Լ� ȣ�� ��" << endl;
	return 0;

}