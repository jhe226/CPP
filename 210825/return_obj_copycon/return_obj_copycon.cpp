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

	SoSimple& Addnum(int n)	// ������ ��ȯ
	{
		num += n;
		// �� ������ �����ϴ� ��ü �ڽ��� ��ȯ, ��ȯ���� �������̶� ������ ��ȯ
		return *this;
	}

	void ShowData()
	{
		cout << "num : " << num << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob)		// ������ ����
{
	// �Ű� ���� ���� ���� -> ���� ������ ȣ��
	// 2. Call-by-Value ������ �Լ� ȣ�� �������� ��ü�� ���ڷ� �����ϴ� ���

	// ��ü�� ��ȯ�ϵ�, ���������� ��ȯ���� �ʴ� ���
	cout << "return ����" << endl;
	return ob;
}

int main()
{
	SoSimple obj(7);

	// SimpleFuncObj���� ��ȯ�� ��ü�� ������� Addnum() ȣ��, Addnum() ��ȯ
	// �������� ������� ShowData()ȣ��
	SimpleFuncObj(obj).Addnum(30).ShowData();
	obj.ShowData();
	
	return 0;

}