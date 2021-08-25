#include<iostream>

using namespace std;

// 복사 생성자가 호출되는 시점
// 1. 기존에 생성된 객체를 이용해서 새로운 객체를 초기화 하는 경우
// 2. Call-by-Value 방식의 함수 호출 과정에서 객체를 인자로 전달하는 경우
// 3. 객체를 반환하되, 참조형으로 반환하지 않는 경우

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{

	}

	SoSimple(const SoSimple& copy) : num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple& copy)" << endl;
	}

	void ShowData()
	{
		cout << "num : " << num << endl;
	}
};

void SimpleFuncObj(SoSimple ob)		// 값으로 받음
{
	// void void SimpleFuncObj(SoSimple& ob)	// 참조로 받음

	// 인자 전달 시 선언과 동시에 초기화
	ob.ShowData();
}

int main()
{
	SoSimple obj(7);
	cout << "함수 호출 전" << endl;
	// 객체 obj 를 인자로 전달
	SimpleFuncObj(obj);
	cout << "함수 호출 후" << endl;
	return 0;

}