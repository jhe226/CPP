#include<iostream>

using namespace std;

// static 멤버변수(클래스 변수) : 객체 별로 존재하는 변수가 아닌 프로그램 전체 영역에서 하나만 존재하는 변수

class SoSimple
{
private :
	static int simObjCnt;
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};
int SoSimple::simObjCnt = 0;	// static 멤버 변수 초기화

class SoComplex
{
private:
	static int cmxObjCnt;
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}

	SoComplex(SoComplex& copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;


int main()
{
	SoSimple sim1;		// 첫 번째 SoSimple 객체
	SoSimple sim2;		// 두 번째 SoSimple 객체

	SoComplex com1;				// 첫 번째 SoComplex 객체
	SoComplex com2 = com1;		// 두 번째 SoComplex 객체
	SoComplex();				// 세 번째 SoComplex 객체

	return 0;

}