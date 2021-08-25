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

	SoSimple& Addnum(int n)	// 참조형 반환
	{
		num += n;
		// 이 문장을 실행하는 객체 자신을 반환, 반환형이 참조형이라 참조값 반환
		return *this;
	}

	void ShowData()
	{
		cout << "num : " << num << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob)		// 값으로 받음
{
	// 매개 변수 전달 과정 -> 복사 생성자 호출
	// 2. Call-by-Value 형식의 함수 호출 과정에서 객체를 인자로 전달하는 경우

	// 객체를 반환하되, 참조형으로 반환하지 않는 경우
	cout << "return 이전" << endl;
	return ob;
}

int main()
{
	SoSimple obj(7);

	// SimpleFuncObj에서 반환된 객체를 대상으로 Addnum() 호출, Addnum() 반환
	// 참조값을 대상으로 ShowData()호출
	SimpleFuncObj(obj).Addnum(30).ShowData();
	obj.ShowData();
	
	return 0;

}