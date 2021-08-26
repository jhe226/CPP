#include<iostream>

using namespace std;

// 자식 클래스의 객체 생성 과정 : 생성자의 실행 순서
// 결론 : 부모 클래스의 생성자가 먼저 실행된다
// 부모 클래스의 생성자를 호출하지 않으면 void 생성자가 실행

class SoBase
{
private:
	int baseNum;
public:
	SoBase():baseNum(20)
	{
		cout << "SoBase()" << endl;

	}
	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase(int n)" << endl;
	}
	void ShowBaseData()
	{
		cout << baseNum << endl;
	}
};

class SoDerived :public SoBase
{
private:
	int derivNum;
public:
	SoDerived() : derivNum(30)
		//이니셜라이저를 통한 부모 클래스의 생성자 호출이 명시적으로 정의되어 있지 않으므로 void 생성자 호출
	{
		cout << "SoDerived()" << endl;
	}
	SoDerived(int n) : derivNum(n)
	{
		cout << "Soderived(int n)" << endl;
	}
	SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)
	{
		cout << "SoDerived(int n1, int n2)" << endl;
	}
	void ShowDerivData()
	{
		ShowBaseData();
		cout << derivNum << endl;
	}
};

int main()
{
	cout << "case1....." << endl;
	SoDerived dr1;
	SoBase();
	SoDerived();
	dr1.ShowDerivData();
	cout << "-----------------" << endl;

	cout << "case2....." << endl;
	SoDerived dr2(12);
	SoBase();
	SoDerived();
	dr2.ShowDerivData();
	cout << "-----------------" << endl;

	cout << "case3....." << endl;
	SoDerived dr3(12);
	SoBase();
	SoDerived();
	dr3.ShowDerivData();
	
	return 0;
}