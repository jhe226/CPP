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

	sim3 = sim1;	// 주소가 아닌 값을 복사
	sim3.ShowSimpleData();
	cout << &sim3 << endl;
	cout << &sim1 << endl;

	sim3.SetNum1(100);	// 값 하나만 변경 -> 둘 중 하나만 바뀜 -> 값 복사 
	sim3.ShowSimpleData();	// 100 30
	sim1.ShowSimpleData();	// 15 30

	// 얕은 복사의 경우 (참조 복사)
	SoSimple *sim1New = new SoSimple(15, 30);
	cout << "생성 및 초기화 직전" << endl;
	SoSimple *sim2New = new SoSimple(15, 30);
	sim2New->SetNum1(100);
	sim1New->ShowSimpleData();	// 15 30
	sim2New->ShowSimpleData();	// 15 30

	// 주소값 확인 -> 서로 다름을 확인
	cout << sim1New << endl;
	cout << sim2New << endl;

	sim2New = sim1New;
	sim1New->ShowSimpleData();	// 15 30
	sim2New->ShowSimpleData();	// 15 30

	// 하나만 값 변경 -> 둘 다 달라짐 -> 주소 복사
	sim2New->SetNum1(200);
	sim1New->ShowSimpleData();	// 200 30
	sim2New->ShowSimpleData();	// 200 30

	// 동일한 주소 출력
	cout << sim1New << endl;	
	cout << sim2New << endl;

	return 0;
}