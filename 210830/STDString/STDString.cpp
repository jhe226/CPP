#include<iostream>
#include<string>

using namespace std;

// string�� ���ڿ��� ó���ϱ� ���� ���ǵ� Ŭ����
// Ŭ������ ����� ���� ������� <string>�� �����ؾ� �Ѵ�

int main()
{
	string str1 = "I like ";
	string str2 = "string class";

	// string ��ü�� ���� ���� ����
	// operator + �� �����ε� ����
	string str3 = str1 + str2;

	// string Ŭ������ << �����ڿ� ���ؼ��� �����ε�
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3) cout << "���� ���ڿ��Դϴ�" << endl;
	else cout << "�������� ���� ���ڿ��Դϴ�" << endl;

	string str4;
	cout << "���ڿ� �Է� : ";
	cin >> str4;
	cout << "�Է��� ���ڿ� : " << str4 << endl;

	return 0;

}