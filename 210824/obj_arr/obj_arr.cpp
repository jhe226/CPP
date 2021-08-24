#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

// 객체 배열

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
	// 배열 생성시 필요한 생성자 추가
	Person()
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}
	// 원하는 데이터로의 초기화를 목적으로 정의된 함수
	void SetPersonInfo(char*myname, int myage)
	{
		name = myname;
		age = myage;
	}

	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << ", ";
		cout << "나이 : " << age << endl;
	}

	~Person()
	{
		delete[]name;
		cout << "called destructor" << endl;
	}
};

int main()
{
	// 객체 배열
	// 객체로 이루어진 배열 -> 배열 생성 시 객체가 함께 생성
	// 호출되는 생성자 : void 생성자
	
	Person parr[3];	 // called Person()

	char namestr[100];
	char*strptr;
	int age;
	int len;

	// 반복문 안에서 이름과 나이 정보를 받아 객체 초기화

	for (int i = 0; i < 3; i++)
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
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
