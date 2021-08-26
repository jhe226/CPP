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
int SoSimple::simObjCnt = 0;	// static ��� ���� �ʱ�ȭ


int main()
{
	SoSimple::printStatic();

	// cout << SoSimple::num << endl;
	// public���� ����� static�� ���, ��ü ���� ���� Ŭ���� �̸����� �ٷ� ���� ����
	// -> ��ü ���� ���� �̸� �޸𸮿� �ö��ִ�.
	
	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;	// 0��° SoSimple ��ü
	SoSimple sim1;		// ù ��° SoSimple ��ü
	SoSimple sim2;		// �� ��° SoSimple ��ü
	sim2.printStatic();

	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;	// 2��° SoSimple ��ü
	cout << sim1.simObjCnt << "��° SoSimple ��ü" << endl;	// 2��° SoSimple ��ü
	cout << sim2.simObjCnt << "��° SoSimple ��ü" << endl;	// 2��° SoSimple ��ü

	cout << sim1.num << endl;	// 1
	cout << sim1.num << endl;	// 1

	return 0;

}