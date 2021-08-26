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
	// 이니셜라이저 -> 유도 클래스는 기초 클래스의 생성자를 명시적으로 호출해야함
	// 유도 클래스의 생성자는 기초 클래스의 멤버를 초기화 할 의무를 갖는다
	// 단 기초 클래스의 생성자를 명시적으로 호출해서 초기화해야 함

	// 상위클래스에 void 생성자가 있으면 호출 X
	UnivStudent(int myage, const char*myname, const char*mymajor)
		:Person(myage, myname)
	{
		strcpy(major, mymajor);
	}

	void WhoAreYou() const
	{
		WhatYourName();		// UnivStudent 클래스에 없는 함수지만 Person을 상속 받았으므로 사용 가능
		HowOldAreYou();		// Person의 멤버 함수
		cout << "My major is " << major << endl;
		// cout << "I\m " << age << endl;		// 상속 받았지만 private 멤버 함수에는 바로 접근 안됨
	}
};

int main()
{
	// 유도 클래스 UnivStudent는 기초 클래스의 생성자 호출을 위한 인자까지 함께 전달해야함
	// private 멤버는 유도 클래스에서는 접근 불가 -> 생성자 호출을 통해 기초 클래스의 멤버 초기화

	UnivStudent ustd1(22, "Lee", "Computer eng.");
	ustd1.WhoAreYou();

	UnivStudent ustd2(21, "Yoon", "Electronic eng.");
	ustd2.WhoAreYou();

	return 0;
}