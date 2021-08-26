#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

// 1. �� Ŭ������ ����� �����������?
// 2. MVC ���� : Model, View, Contril

// ������ ����
// ������ �þ�� ������ Permanet �̿��� �������
// ����)
// ������(Sales): �μ�Ƽ�� ������ ����
// �ӽ���(Temporary) : �ð��� �Ƹ�����Ʈ
// �þ ��� ��� ������ ���ΰ�?

// ������������ Ŭ����(���� ����)
class PermanentWorker
{
private:
	char name[100];
	int salary;
public:
	// PermanentWorker(char* name, int salary)
	PermanentWorker(const char* name, int money)
		: salary(money)
	{
		strcpy(this->name, name);
	}

	int GetPay() const
	{
		return salary;
	}

	void ShowSalaryInfo() const
	{
		cout << "name : " << name << endl;
		cout << "salary : " << GetPay() << endl << endl;

	}
};

// ���� ����� ����� Ŭ���� : ��Ʈ�� Ŭ���� or �ڵ鷯 Ŭ����
class EmployeeHandler
{
private:
	PermanentWorker* empList[50];
	int empNum;
public:
	EmployeeHandler(): empNum(0)
	{ }

	void AddEmployee(PermanentWorker*emp)	// ���ο� ���� ���� ���
	{
		empList[empNum++] = emp;
	}

	void ShowAllSalaryinfo() const	// ��� ������ �̹� �� �޿� ���� ���
	{
		for (int i = 0; i < empNum; i++)
		{
			empList[i]->ShowSalaryInfo();
		}
	}

	void ShowTotalSalary() const	// �̹� �� �޿� �Ѿ� ���
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
		{
			sum += empList[i]->GetPay();
		}
		cout << "salary Sum : " << sum << endl;
	}

	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
		{
			delete empList[i];
		}
	}
};

int main()
{
	// ���� ������ �������� ����� ��Ʈ�� Ŭ������ ��ü ����
	EmployeeHandler handler;

	// ���� ���
	handler.AddEmployee(new PermanentWorker("Kim", 1000));
	handler.AddEmployee(new PermanentWorker("Lee", 1500));
	handler.AddEmployee(new PermanentWorker("Jun", 2000));

	// �̹� �޿� �����ؾ��� �޿� ����
	handler.ShowAllSalaryinfo();

	// �̹��޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();
	return 0;
}