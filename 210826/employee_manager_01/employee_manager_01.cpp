#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

// 1. 왜 클래스의 상속이 만들어졌을까?
// 2. MVC 패턴 : Model, View, Contril

// 문제의 접근
// 직원이 늘어나서 정규직 Permanet 이외의 고용형태
// 예시)
// 영업직(Sales): 인센티브 개념의 도임
// 임시직(Temporary) : 시간제 아르바이트
// 늘어날 경우 어떻게 수정할 것인가?

// 정규직원관리 클래스(저장 목적)
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

// 실제 기능을 담당할 클래스 : 컨트롤 클래스 or 핸들러 클래스
class EmployeeHandler
{
private:
	PermanentWorker* empList[50];
	int empNum;
public:
	EmployeeHandler(): empNum(0)
	{ }

	void AddEmployee(PermanentWorker*emp)	// 새로운 직원 정보 등록
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

	// 이번 달에 지불해야할 급여 정보
	handler.ShowAllSalaryinfo();

	// 이번달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	return 0;
}