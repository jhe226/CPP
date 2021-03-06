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
	
	// 함께 선언된 변수에는 직접 접근이 가능 -> 매개변수 필요X

	void ShowCarState()	// const : 값 변경 불가, 출력만 가능.
	{
		cout << "소유자 ID : " << gamerID << endl;
		cout << "연료량 : " << fuelGauge << endl;
		cout << "현재 속도 : " << curSpeed << endl;
	}

	void Accel()
	{
		if (fuelGauge <= 0) return;
		else fuelGauge -= FUEL_STEP;

		if (curSpeed + ACC_STEP >= MAX_SPD)
		{
			curSpeed = MAX_SPD;
			return;
		}

		curSpeed += ACC_STEP;
	}

	void Break()
	{
		if (curSpeed < BRK_STEP)
		{
			curSpeed = 0;
			return;
		}

		curSpeed -= BRK_STEP;
	}
};



int main()
{
	Car run99 = { "run99", 100, 0 };
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();

	run99.Break();
	run99.ShowCarState();

	Car run77 = { "run77", 100, 0 };
	run77.Accel();
	run77.ShowCarState();

	run77.Break();
	run77.ShowCarState();
}