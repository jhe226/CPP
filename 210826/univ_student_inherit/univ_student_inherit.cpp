#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

class Person
{
private:
	char name[50];
	int age;

public:
	Person(int myage, const char*myname) :age(myage)
	{
		strcpy(name, myname);
	}
	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}
	void HowOldAreYou() const
	{
		cout << "I'm " << age << endl;
	}
};

class UnivStudent :public Person
{
private:
	char major[50];
public:
	// �̴ϼȶ����� -> ���� Ŭ������ ���� Ŭ������ �����ڸ� ��������� ȣ���ؾ���
	// ���� Ŭ������ �����ڴ� ���� Ŭ������ ����� �ʱ�ȭ �� �ǹ��� ���´�
	// �� ���� Ŭ������ �����ڸ� ��������� ȣ���ؼ� �ʱ�ȭ�ؾ� ��

	// ����Ŭ������ void �����ڰ� ������ ȣ�� X
	UnivStudent(int myage, const char*myname, const char*mymajor)
		:Person(myage, myname)
	{
		strcpy(major, mymajor);
	}

	void WhoAreYou() const
	{
		WhatYourName();		// UnivStudent Ŭ������ ���� �Լ����� Person�� ��� �޾����Ƿ� ��� ����
		HowOldAreYou();		// Person�� ��� �Լ�
		cout << "My major is " << major << endl;
		// cout << "I\m " << age << endl;		// ��� �޾����� private ��� �Լ����� �ٷ� ���� �ȵ�
	}
};

int main()
{
	// ���� Ŭ���� UnivStudent�� ���� Ŭ������ ������ ȣ���� ���� ���ڱ��� �Բ� �����ؾ���
	// private ����� ���� Ŭ���������� ���� �Ұ� -> ������ ȣ���� ���� ���� Ŭ������ ��� �ʱ�ȭ

	UnivStudent ustd1(22, "Lee", "Computer eng.");
	ustd1.WhoAreYou();

	UnivStudent ustd2(21, "Yoon", "Electronic eng.");
	ustd2.WhoAreYou();

	return 0;
}