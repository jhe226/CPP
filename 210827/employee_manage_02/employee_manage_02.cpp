#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

// ��� ���� Ŭ������ ��ü�� Employee Ŭ������ ��ü�� ����(ó��)�� �� �ִ� ��� ����
// ��Ʈ�� Ŭ���� ���忡���� ��� ��ü�� Employee ��ü�� �����ص� OK.

// ������� �ǹ��ϴ� Employee Ŭ������ �߰�.
// ��� ����� : �̸� O -> �̿� ���õ� ��� ������� ����

class Employee
{
private:
	char name[100];
public:
	Employee(const char*name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name : " << name << endl;
	}
};

// ������ PermanentWorker Ŭ�������� ���� : Employee Ŭ���� ���
// -> �̸��� ���õ� ��� ��� ����
class PermanentWorker:public Employee
{
private:
	int salary;
public:
	// PermanentWorker(char* name, int salary)
	PermanentWorker(const char*name, int money)
		: Employee(name), salary(money)
	{
	}

	int GetPay() const
	{
		return salary;
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary : " << GetPay() << endl << endl;

	}
};

// ���� ����� ����� Ŭ���� : ��Ʈ�� Ŭ���� or �ڵ鷯 Ŭ����
class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }

	void AddEmployee(PermanentWorker*emp)	// ���ο� ���� ���� ���
	{
		empList[empNum++] = emp;
	}

	void ShowAllSalaryinfo() const	// ��� ������ �̹� �� �޿� ���� ���
	{
		/*
		for (int i = 0; i < empNum; i++)
		{
			empList[i]->ShowSalaryInfo();
		}
		*/

	}

	void ShowTotalSalary() const	// �̹� �� �޿� �Ѿ� ���
	{
		int sum = 0;
		/*
		for (int i = 0; i < empNum; i++)
		{
			sum += empList[i]->GetPay();
		}
		*/
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