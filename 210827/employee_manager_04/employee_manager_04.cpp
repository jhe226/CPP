#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

class Employee	// 가상 함수 추가
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

	virtual int GetPay() const
	{
		return 0;
	}

	virtual void ShowSalaryInfo() const
	{ }
};

// 이전의 PermanentWorker 클래스와의 차이 : Employee 클래스 상속
// -> 이름과 관련된 멤버 모두 제거
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

class SalesWorker :public PermanentWorker
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

// 실제 기능을 담당할 클래스 : 컨트롤 클래스 or 핸들러 클래스
class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }

	void AddEmployee(Employee*emp)	// 새로운 직원 정보 등록
	{
		empList[empNum++] = emp;
	}

	void ShowAllSalaryinfo() const	// 모든 직원의 이번 달 급여 정보 출력
	{
		
		for (int i = 0; i < empNum; i++)
		{
			empList[i]->ShowSalaryInfo();
		}

	}

	void ShowTotalSalary() const	// 이번 달 급여 총액 출력
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
	// 직원 관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
	EmployeeHandler handler;

	// 직원 등록
	handler.AddEmployee(new PermanentWorker("Kim", 1000));
	handler.AddEmployee(new PermanentWorker("Lee", 1500));
	handler.AddEmployee(new PermanentWorker("Jun", 2000));

	TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	SalesWorker * seller = new SalesWorker("Hwang", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	// 이번 달에 지불해야할 급여 정보
	handler.ShowAllSalaryinfo();

	// 이번달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	return 0;
}