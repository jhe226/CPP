#include<iostream>

using namespace std;

// this �������� ����

class TwoNumber
{
private:
	int num1;
	int num2;

public:
	// �Ű������� void������ ����Ǵ� ����Ʈ ������ -> �����ڰ� �ϳ��� ���ǵǾ����� ���� ������ ����
	TwoNumber(int num1, int num2)
	{
		// this->num1�� ������� num1 �� �ǹ�
		// ��ü�� �ּҰ����� ���ٰ����� ��� -> ������� (��������X)
		// �Ű����� num1, num2�� ���� ���޵� ��-> ������� num1, num2�� ����
		// ������ ���� ������ �켱���� ����
		// TwoNumber() = default;
		this->num1 = num1;
		this->num2 = num2;
	}
	/*
		��� �̴ϼȶ����������� this ������ ��� �Ұ�.
		���, �����ϴ� ���� : ������� -> ����Ǵ� ��(�Ұ�ȣ ���� ����)�� �Ű� ������ �ν�
		�տ� �ִ� ���� : ��������, �Ұ�ȣ �ȿ� �ִ� ���� : ������� 
		TwoNumber(int num1, int num2)
			: num1(num1), num2(num2)
		{
			// empty
		}
	*/

	void ShowTwoNumber()
	{
		// this �����͸� ��� -> ��� ������ �������� ��Ȯ����
		// �׷��� �Ϲ������� �̷��� ��쿡�� this ������ ����
		cout << this->num1 << endl;
		cout << this->num2 << endl;
	}
};

int main()
{
	TwoNumber(2, 3);
}