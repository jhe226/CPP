#include<iostream>

using namespace std;

// 전역 변수에 선언된 static의 의미 : 선언된 파일 내에서만 참조 허용
// 함수 내에 선언된 static의 의미 : 한번만 초기화 되고, 지역변수와 달리 함수를 빠져나가도 소멸 X

void Counter()
{
	static int cnt;		// 0으로 초기화하지 않아도 	
	cnt++;
	cout << "Current cnt: " << cnt << endl;
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		Counter();
	}

	return 0;
}
