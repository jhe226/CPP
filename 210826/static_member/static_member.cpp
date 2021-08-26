#include<iostream>

using namespace std;

// static �������(Ŭ���� ����) : ��ü ���� �����ϴ� ������ �ƴ� ���α׷� ��ü �������� �ϳ��� �����ϴ� ����

class SoSimple
{
private :
	static int simObjCnt;
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
	}
};
int SoSimple::simObjCnt = 0;	// static ��� ���� �ʱ�ȭ

class SoComplex
{
private:
	static int cmxObjCnt;
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}

	SoComplex(SoComplex& copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;


int main()
{
	SoSimple sim1;		// ù ��° SoSimple ��ü
	SoSimple sim2;		// �� ��° SoSimple ��ü

	SoComplex com1;				// ù ��° SoComplex ��ü
	SoComplex com2 = com1;		// �� ��° SoComplex ��ü
	SoComplex();				// �� ��° SoComplex ��ü

	return 0;

}