#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

// ��ü �迭

class Person
{
private:
	char*name;
	int age;
public:
	Person(char*myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	// �迭 ������ �ʿ��� ������ �߰�
	Person()
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	// ���ϴ� �����ͷ��� �ʱ�ȭ�� �������� ���ǵ� �Լ�
	void SetPersonInfo(char*myname, int myage)
	{
		name = myname;
		age = myage;
	}

	void ShowPersonInfo() const
	{
		cout << "�̸� : " << name << ", ";
		cout << "���� : " << age << endl;
	}

	~Person()
	{
		delete[]name;
		cout << "called destructor" << endl;
	}
};

int main()
{
	// ��ü �迭
	// ��ü�� �̷���� �迭 -> �迭 ���� �� ��ü�� �Բ� ����
	// ȣ��Ǵ� ������ : void ������
	
	Person parr[3];	 // called Person()

	char namestr[100];
	char*strptr;
	int age;
	int len;

	// �ݺ��� �ȿ��� �̸��� ���� ������ �޾� ��ü �ʱ�ȭ

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸� : ";
		cin >> namestr;
		cout << "���� : ";
		cin >> age;

		len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy(strptr, namestr);
		parr[i].SetPersonInfo(strptr, age);
	}

	parr[0].ShowPersonInfo();
	parr[1].ShowPersonInfo();
	parr[2].ShowPersonInfo();
}
