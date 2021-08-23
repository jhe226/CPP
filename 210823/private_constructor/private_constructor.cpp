#include<iostream>

using namespace std;

// private 생성자 : AAA 클래스의 멤버 함수 내에서도 AAA 클래스의 객체 생성 가능
// AAA 클래스의 멤버 함수 내에서도 AAA 클래스의 객체 생성 가능
// 생성자가 private -> 외부에서의 객체 생성 허용X

class AAA
{
private:
	int num;
public:
	AAA() : num(0) {}
	AAA& CreateInitObj(int n) const
	{
		AAA* ptr = new AAA(n);	// 클래스 내부 -> private 생성자 호출 가능
		return *ptr;
	}
	void ShowNum() const { cout << num << endl; }

private:
	// 생성자가 private -> 클래스 외부에서는 이 생성자의 호출을 통해 객체 생성 불가
	AAA(int n) : num(n) {}
};

int main()
{
	// AAA base(1); -> 불가(생성자 private)
	AAA base;
	base.ShowNum();

	AAA& obj1 = base.CreateInitObj(3);
	obj1.ShowNum();

	AAA& obj2 = base.CreateInitObj(12);
	obj2.ShowNum();

	delete& obj1;
	delete& obj2;

	return 0;
}