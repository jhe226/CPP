#include<iostream>

using namespace std;

// 'true' : ��'�� �ǹ��ϴ� 1byte ������, 1 (����X)
// 'false' : '����'�� �ǹ��ϴ� 1byte ������, 0 (����X)
// ������ �;��� ��ġ�� ���� �Ǹ�, ���� 1�� 0���� ��ȯ�ȴ�.

int main()
{
	int num = 10;
	int i = 0;

	cout << "true  : " << true << endl;
	cout << "false  : " << false << endl;

	while (true)	// ���ѷ���
	{
		cout << i++ << ' ';		 // 0 ~ 10
		if (i > num) break;
		cout << endl;

		cout << "sizeof 1 :" << sizeof(1) << endl;
		cout << "sizeof 0 :" << sizeof(0) << endl;
		cout << "sizeof true :" << sizeof(true) << endl;
		cout << "sizeof false :" << sizeof(false) << endl;
	}
}