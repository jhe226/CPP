#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

// ����Ʈ ���� �������� ������ : �Ҹ��� ����
// ���� �߻� ���� : ���� ����(�� ����) -> �Ҹ��ڿ� �ִ� delete���� ���� �߻� 

class Person
{
	char*name;
	int age;
public:
	// Person(char*myname, int myage)
	Person(const char*myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}

	void ShowPersonInfo() const
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}

	~Person()
	{
		// delete[]name; //  ���� �߻�
		cout << "called destructor" << endl;
	}
};

int main() {
	Person man1("Lee", 29);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
}
