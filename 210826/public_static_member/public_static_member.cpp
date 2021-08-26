#include<iostream>

using namespace std;

class SoSimple
{
private:

public:
	static int simObjCnt;
	int num = 0;
	SoSimple()
	{
		simObjCnt++;
		num++;
	}
	static void printStatic()
	{
		cout << simObjCnt << endl;
	}
};
int SoSimple::simObjCnt = 0;	// static 멤버 변수 초기화


int main()
{
	SoSimple::printStatic();

	// cout << SoSimple::num << endl;
	// public으로 선언된 static의 경우, 객체 생성 없이 클래스 이름으로 바로 접근 가능
	// -> 객체 생성 전에 미리 메모리에 올라가있다.
	
	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;	// 0번째 SoSimple 객체
	SoSimple sim1;		// 첫 번째 SoSimple 객체
	SoSimple sim2;		// 두 번째 SoSimple 객체
	sim2.printStatic();

	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;	// 2번째 SoSimple 객체
	cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;	// 2번째 SoSimple 객체
	cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;	// 2번째 SoSimple 객체

	cout << sim1.num << endl;	// 1
	cout << sim1.num << endl;	// 1

	return 0;

}