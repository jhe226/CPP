#include<iostream>

using namespace std;

// 다형성(polymorphism) : 상속 관계에 있는 하나의 객체가 여러가지 타입을 결정할 수 있는 것
// 모든 객체를 가리킬 수 있음(객체 주소값 저장 O)

class Person
{
public:
	void Sleep() { cout << "Sleep" << endl; }
};

class Student:public Person
{
public:
	void Study() { cout << "Study" << endl; }
};

class PartTimeStudent:public Student
{
public:
	void work() { cout << "Work" << endl; }
};

int main()
{
	Person*ptr1 = new Student();
	Person*ptr2 = new PartTimeStudent();
	Student*ptr3 = new PartTimeStudent();

	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();

	delete ptr1;
	delete ptr2;
	delete ptr3;

	return 0;
}