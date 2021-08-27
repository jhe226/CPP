#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

// 모든 직원 클래스의 객체를 Employee 클래스의 객체로 간주(처리)할 수 있는 기반 마련
// 컨트롤 클래스 입장에서는 모든 객체를 Employee 객체로 간주해도 OK.

// 고용인을 의미하는 Employee 클래스가 추가.
// 모든 고용인 : 이름 O -> 이와 관련된 멤버 기반으로 정의

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

// 이전의 PermanentWorker 클래스와의 차이 : Employee 클래스 상속
// -> 이름과 관련된 멤버 모두 제거
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

// 실제 기능을 담당할 클래스 : 컨트롤 클래스 or 핸들러 클래스
class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }

	void AddEmployee(PermanentWorker*emp)	// 새로운 직원 정보 등록
	{
		empList[empNum++] = emp;
	}

	void ShowAllSalaryinfo() const	// 모든 직원의 이번 달 급여 정보 출력
	{
		/*
		for (int i = 0; i < empNum; i++)
		{
			empList[i]->ShowSalaryInfo();
		}
		*/

	}

	void ShowTotalSalary() const	// 이번 달 급여 총액 출력
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
	// 직원 관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
	EmployeeHandler handler;

	// 직원 등록
	handler.AddEmployee(new PermanentWorker("Kim", 1000));
	handler.AddEmployee(new PermanentWorker("Lee", 1500));
	handler.AddEmployee(new PermanentWorker("Jun", 2000));

	// 이번 달에 지불해야할 급여 정보
	handler.ShowAllSalaryinfo();

	// 이번달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	return 0;
}