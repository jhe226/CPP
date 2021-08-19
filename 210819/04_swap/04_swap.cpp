#include<iostream>

using namespace std;

// �����ڸ� �̿��� Call-by-Reference

// �Ű������� �Լ��� ȣ��� �� ������ �Ǵ� ���� -> �Լ� ȣ�� �������� ����� ���ÿ� ���޵Ǵ� ������� �ʱ�ȭ
// �Ű������� ����� �����ڴ� ����� ���ÿ� �ʱ�ȭ

void SwapRef2(int &ref1, int &ref2)
{
	// �����ڷ� �޴� ��� �ش� �޸𸮷� ���� ���� -> ���� ����

	int tmp = ref1;
	ref1 = ref2;
	ref2 = tmp;
}

int main()
{
	int val1 = 10;
	int val2 = 20;

	SwapRef2(val1, val2);
	cout << "val1 : " << val1 << endl;
	cout << "val2 : " << val2 << endl;

	return 0;
}