#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

// ��ü ������ �迭

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
	// ��ü ������ �迭
	// ��ü�� ������ �� �ִ� ������ ������ �̷���� �迭
	// ������ ��ü ���� ���� �ʿ�
	// ������ ���� X

	// ������ �迭 ���� -> �� 3�� ���� �迭
	Person* parr[3];	 // called Person()

	char namestr[100];
	int age;

	// �ݺ��� �ȿ��� �̸��� ���� ������ �޾� ��ü �ʱ�ȭ

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸� : ";
		cin >> namestr;
		cout << "���� : ";
		cin >> age;

		// ��ü ���� -> ��ü �ּҰ��� �迭�� ����
		parr[i] = new Person(namestr, age);		// ������ ��ü ���� ����
	}

	parr[0]->ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();

	// 3ȸ�� ���� new ���� ���� -> 3ȸ delete ����
	delete parr[0];
	delete parr[1];
	delete parr[2];
	/*
	for(int i = 0; i < 3; i++)
	{
		delete parr[i];
	}
	*/
}
