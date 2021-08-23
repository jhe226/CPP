#define _CRT_SECURE_NO_WARINGS
#include<iostream>
#include<cstring>

using namespace std;

// �����ڿ� ���������� �Ҹ��ڵ� �������� ������ ����Ʈ �Ҹ��ڰ� ����

class Person
{
private:
	char* name;
	int age;
public:
	// Person(char* myname, int myage)
	Person(const char* myname, int myage)
		// ������ �ö󰡸鼭 ���ͷ� ���ڸ� ���ڷ� �ѱ� �� ���� Ÿ���� const�� �����ϵ��� �ٲ�
	{
		// ���ʿ��� �޸� ������ ���� �ɴ� ������ ��������
		// ���ڿ��� ���̸�ŭ �޸� ������ ���� �Ҵ�

		int len = strlen(myname) + 1;
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
		// �����ڿ��� �Ҵ��� �޸� ������ �Ҹ��Ű�� ���� ��ġ�� �Ҹ���
		// �޸� ������ �Ҹ꿡 ���� �ڵ� ����

		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main()
{
	Person man1("Lee Dong Woo", 29);
	Person man2("Jang Dong Gun", 41);

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}