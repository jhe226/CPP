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
class PermanentWorker :public Employee
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

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int PayPerHour;
public:
	TemporaryWorker(const char*name, int pay)
		: Employee(name), workTime(0), PayPerHour(pay)
	{ }

	void AddWorkTime(int time)
	{
		workTime += time;
	}

	int GetPay() const
	{
		return workTime * PayPerHour;
	}

	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary : " << GetPay() << endl << endl;
	}
};

class SalesWorker:public PermanentWorker
{
private:
	int salesResult;
	double bonusRatio;

public:
	SalesWorker(const char*name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{ }

	void AddSalesResult(int value)
	{
		salesResult += value;
	}

	int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
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

	void AddEmployee(Employee*emp)	// ���ο� ���� ���� ���
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

	TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	SalesWorker * seller = new SalesWorker("Hwang", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	// �̹� �޿� �����ؾ��� �޿� ����
	handler.ShowAllSalaryinfo();

	// �̹��޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();
	return 0;
}