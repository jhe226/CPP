#include<iostream>

using namespace std;

// 'true' : 참'을 의미하는 1byte 데이터, 1 (정수X)
// 'false' : '거짓'을 의미하는 1byte 데이터, 0 (정수X)
// 정수가 와야할 위치에 오게 되면, 각각 1과 0으로 변환된다.

int main()
{
	int num = 10;
	int i = 0;

	cout << "true  : " << true << endl;
	cout << "false  : " << false << endl;

	while (true)	// 무한루프
	{
		cout << i++ << ' ';		 // 0 ~ 10
		if (i > num) break;
		cout << endl;

		cout << "sizeof 1 :" << sizeof(1) << endl;
		cout << "sizeof 0 :" << sizeof(0) << endl;
		cout << "sizeof true :" << sizeof(true) << endl;
		cout << "sizeof false :" << sizeof(false) << endl;
	}
}
