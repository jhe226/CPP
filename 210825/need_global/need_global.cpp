#include<iostream>

using namespace std;

// ������ �ʿ�

int simObjCnt = 0;	// SoSimple Ŭ������ ��ü�� �� �� �����Ǿ����� ���
int cmxObjCnt = 0;	// SoComplex Ŭ������ ��ü�� �� �� �����Ǿ����� ���

class SoSimple
{
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
	}
};

class SoComplex
{
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


int main()
{
	SoSimple sim1;		// ù ��° SoSimple ��ü
	SoSimple sim2;		// �� ��° SoSimple ��ü

	SoComplex com1;				// ù ��° SoComplex ��ü
	SoComplex com2 = com1;		// �� ��° SoComplex ��ü
	SoComplex();				// �� ��° SoComplex ��ü

	return 0;

}