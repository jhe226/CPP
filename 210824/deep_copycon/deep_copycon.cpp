#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

// 디폴트 복사 생성자의 문제점 : 소멸자 문제
// 에러 발생 이유 : 얕은 복사(값 복사) -> 소멸자에 있는 delete에서 에러 발생 

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

	Person(const Person& copy)
		:age(copy.age)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}

	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}

	~Person()
	{
		delete[]name; //  에러 발생
		cout << "called destructor" << endl;
	}
};

int main() {
	Person man1("Lee", 29);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
}
