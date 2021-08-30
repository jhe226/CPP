#include<iostream>
using namespace std;

// �Լ� �ۺ� : "�Լ��� ����� ����" -> �Լ� ����� �����Ǿ� ������ �ڷ����� �������� �ʾ� �����ؾ���

// 1) <typename T> ��� <class T> ����ص� �ȴ�
// 2) T ��� �ٸ� ���� ��� ����

template <typename T>
T Add(T num1, T num2)	// �Ʒ��� �Լ��� ���ø����� ����
{
	return num1 + num2
}

int main()
{
	cout << Add<int>(15, 20) << endl;
	cout << Add<double>(2.9, 3.7) << endl;
	cout << Add<int>(3.2, 3.2) << endl;
	cout << Add<double>(3.14, 2.75) << endl;

	return 0;
}