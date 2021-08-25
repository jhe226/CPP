#include<iostream>

using namespace std;

// 전역의 필요

int simObjCnt = 0;	// SoSimple 클래스의 객체가 몇 번 생성되었는지 기록
int cmxObjCnt = 0;	// SoComplex 클래스의 객체가 몇 번 생성되었는지 기록

class SoSimple
{
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};

class SoComplex
{
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


int main()
{
	SoSimple sim1;		// 첫 번째 SoSimple 객체
	SoSimple sim2;		// 두 번째 SoSimple 객체

	SoComplex com1;				// 첫 번째 SoComplex 객체
	SoComplex com2 = com1;		// 두 번째 SoComplex 객체
	SoComplex();				// 세 번째 SoComplex 객체

	return 0;

}