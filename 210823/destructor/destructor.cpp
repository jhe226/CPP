#define _CRT_SECURE_NO_WARINGS
#include<iostream>
#include<cstring>

using namespace std;

// 생성자와 마찬가지로 소멸자도 정의하지 않으면 디폴트 소멸자가 삽입

class Person
{
private:
	char* name;
	int age;
public:
	// Person(char* myname, int myage)
	Person(const char* myname, int myage)
		// 버전이 올라가면서 리터럴 문자를 인자로 넘길 때 인자 타입을 const로 선언하도록 바뀜
	{
		// 불필요한 메모리 공간의 낭비 또는 부족을 막기위해
		// 문자열의 길이만큼 메모리 공간을 동적 할당

		int len = strlen(myname) + 1;
		strcpy(name, myname);
		age = myage;
	}

	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}

	~Person()
	{
		// 생성자에서 할당한 메모리 공간을 소멸시키기 좋은 위치가 소멸자
		// 메모리 공간의 소멸에 대한 코드 삽입
		cout << "이름 : " << name << endl;
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
