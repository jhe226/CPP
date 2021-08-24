#include<iostream>

using namespace std;

// C++ ��Ÿ���� �ʱ�ȭ
// sim2�� sim1 ������ ���� �����ڰ� ���� �� -> ���� ������
// ���� ������ �ǹ�ó�� ���� ��� �� ����� ���簡 �Ͼ
class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2)
		: num1(n1), num2(n2)
	{
		// empty
	}
	// ���� ������
	// ���� �����ڸ� �������� ������ ��� �� ����� ���縦 �����ϴ� ����Ʈ ���� �����ڰ� ����
	// SoSimple(SoSimple& copy) : num1(copy.num1), num2(copy.num2)
	// {}
	SoSimple(SoSimple& copy)
		: num1(copy.num1), num2(copy.num2)
	{
		cout << "Called SoSimple(Sosimple &copy)" << endl;
	}

	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}

	void SetNum1(int n)
	{
		num1 = n;
	}
};
int main()
{
	SoSimple sim1(15, 30);
	cout << "���� �� �ʱ�ȭ ����" << endl;
	SoSimple sim2 = sim1;	// Called SoSimple(SoSimple &copy)/ SoSimle sim2(sim1);
	// SoSimple sim2(sim1); ���� ��ȯ
	// 1. SoSimple�� ��ü ����
	// 2. ��ü�� �̸��� sim2�� ���Ѵ�
	// 3. sim1�� ���ڷ� ���� �� �ִ� �������� ȣ���� ���� ��ü ���� �Ϸ�

	cout << "���� �� �ʱ�ȭ ����" << endl;
	sim2.ShowSimpleData();

	SoSimple sim3(25, 40);
	sim3.ShowSimpleData();
	cout << &sim3 << endl;
	cout << &sim1 << endl;

	sim3 = sim1;	// �ּҰ� �ƴ� ���� ����
	sim3.ShowSimpleData();
	cout << &sim3 << endl;
	cout << &sim1 << endl;

	sim3.SetNum1(100);	// �� �ϳ��� ���� -> �� �� �ϳ��� �ٲ� -> �� ���� 
	sim3.ShowSimpleData();	// 100 30
	sim1.ShowSimpleData();	// 15 30

	// ���� ������ ��� (���� ����)
	SoSimple *sim1New = new SoSimple(15, 30);
	cout << "���� �� �ʱ�ȭ ����" << endl;
	SoSimple *sim2New = new SoSimple(15, 30);
	sim2New->SetNum1(100);
	sim1New->ShowSimpleData();	// 15 30
	sim2New->ShowSimpleData();	// 15 30

	// �ּҰ� Ȯ�� -> ���� �ٸ��� Ȯ��
	cout << sim1New << endl;
	cout << sim2New << endl;

	sim2New = sim1New;
	sim1New->ShowSimpleData();	// 15 30
	sim2New->ShowSimpleData();	// 15 30

	// �ϳ��� �� ���� -> �� �� �޶��� -> �ּ� ����
	sim2New->SetNum1(200);
	sim1New->ShowSimpleData();	// 200 30
	sim2New->ShowSimpleData();	// 200 30

	// ������ �ּ� ���
	cout << sim1New << endl;	
	cout << sim2New << endl;

	return 0;
}