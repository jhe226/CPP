#include<iostream>

using namespace std;

// const와 함수 오버로딩
class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{

	}

	SoSimple& Addnum(int n)
	{
		num += n;
		return *this;
	}

	// 함수의 const 선언 유무는 함수 오버로딩의 조건
	void SimpleFunc()
	{
		cout << "SimpleFunc : " << num << endl;
	}

	void SimpleFunc() const
	{
		cout << "const SimpleFunc : " << num << endl;
	}
};

// const 객체 또는 참조자를 대상으로 멤버함수 호출 시 const 선언된 멤버함수가 선언된다.
SoSimple YourFunc(const SoSimple& obj)
{
	obj.SimpleFunc();
}

int main()
{
	SoSimple obj1(2);
	const SoSimple obj2(7);
	
	obj1.SimpleFunc();
	obj2.SimpleFunc();


	YourFunc(obj1);		// const SimpleFunc : 2
	YourFunc(obj2);		// const SimpleFunc : 2

	return 0;

}