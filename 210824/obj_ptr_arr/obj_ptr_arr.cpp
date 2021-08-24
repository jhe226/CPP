#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

// 객체 포인터 배열

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
	// 객체 포인터 배열
	// 객체를 저장할 수 있는 포인터 변수로 이루어진 배열
	// 별도의 객체 생성 과정 필요
	// 생성자 실행 X

	// 포인터 배열 선언 -> 값 3개 저장 배열
	Person* parr[3];	 // called Person()

	char namestr[100];
	int age;

	// 반복문 안에서 이름과 나이 정보를 받아 객체 초기화

	for (int i = 0; i < 3; i++)
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
		cin >> age;

		// 객체 생성 -> 객체 주소값을 배열에 저장
		parr[i] = new Person(namestr, age);		// 별도의 객체 생성 과정
	}

	parr[0]->ShowPersonInfo();
	parr[1]->ShowPersonInfo();
	parr[2]->ShowPersonInfo();

	// 3회에 걸쳐 new 연산 진행 -> 3회 delete 연산
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
