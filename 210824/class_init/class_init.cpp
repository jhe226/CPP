#include<iostream>

using namespace std;

// C++ 스타일의 초기화
// sim2에 sim1 복사할 때도 생성자가 실행 됨 -> 복사 생성자
// 대입 연산의 의미처럼 실제 멤버 대 멤버의 복사가 일어남
class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2)
		: num1(n1), num2(n2)
	{
		// empty
	}
	// 복사 생성자
	// 복사 생성자를 정의하지 않으면 멤버 대 멤버의 복사를 진행하는 디폴트 복사 생성자가 삽입
	// SoSimple(SoSimple& copy) : num1(copy.num1), num2(copy.num2)
	// {}
	SoSimple(SoSimple& copy)
		: num1(copy.num1), num2(copy.num2)
	{
		cout << "Called SoSimple(Sosimple &copy)" << endl;
	}

	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}

	void SetNum1(int n)
	{
		num1 = n;
	}
};
int main()
{
	SoSimple sim1(15, 30);
	cout << "생성 및 초기화 직전" << endl;
	SoSimple sim2 = sim1;	// Called SoSimple(SoSimple &copy)/ SoSimle sim2(sim1);
	// SoSimple sim2(sim1); 으로 변환
	// 1. SoSimple형 객체 생성
	// 2. 객체의 이름은 sim2로 정한다
	// 3. sim1을 인자로 받을 수 있는 생성자의 호출을 통해 객체 생성 완료

	cout << "생성 및 초기화 직후" << endl;
	sim2.ShowSimpleData();

	SoSimple sim3(25, 40);
	sim3.ShowSimpleData();
	cout << &sim3 << endl;
	cout << &sim1 << endl;

	sim3 = sim1;
	sim3.ShowSimpleData();
	cout << &sim3 << endl;
	cout << &sim1 << endl;

	sim3.SetNum1(100);
	sim3.ShowSimpleData();
	sim1.ShowSimpleData();

	return 0;
}