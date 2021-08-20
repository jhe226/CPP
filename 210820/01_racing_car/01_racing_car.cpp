#include<iostream>

using namespace std;

// C++에서 구조체 변수 선언 시 struct 키워드의 생략을 위한 typedef 선언이 불필요함.
// 데이터 뿐만 아니라, 해당 데이터의 연관 함수 모임들도 함께 그룹 형성 -> 함수를 하나로 묶는 것에 대해 가치 부여 O

#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10

struct Car
{
	char gamerID[ID_LEN];
	int fuelGauge;
	int curSpeed;
};

void ShowCarState(const Car &car)	// const : 값 변경 불가, 출력만 가능.
{
	cout << "소유자 ID : " << car.gamerID << endl;
	cout << "연료량 : " << car.fuelGauge << endl;
	cout << "현재 속도 : " << car.curSpeed << endl;
}

void Accel(Car &car)
{
	if (car.fuelGauge <= 0) return;
	else car.fuelGauge -= FUEL_STEP;

	if (car.curSpeed + ACC_STEP >= MAX_SPD)
	{
		car.curSpeed = MAX_SPD;
		return;
	}
	
	car.curSpeed += ACC_STEP;
}

void Break(Car &car)
{
	if (car.curSpeed < BRK_STEP)
	{
		car.curSpeed = 0;
		return;
	}

	car.curSpeed -= BRK_STEP;
}

int main()
{
	Car run99 = { "run99", 100, 0 };
	Accel(run99);
	Accel(run99);
	ShowCarState(run99);

	Break(run99);
	ShowCarState(run99);

	Car run77 = { "run77", 100, 0 };
	Accel(run77);
	ShowCarState(run77);

	Break(run77);
	ShowCarState(run77);
}