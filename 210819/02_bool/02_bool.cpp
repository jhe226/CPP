#include<iostream>

using namespace std;

// 자료형 bool : true와 false의 자료형

bool IsPositive(int num)
{
	if (num < 0) return false;
	else return true;
}

int main()
{
	bool isPos;
	int num;
	cout << "Input number : ";
	cin >> num;

	// isPos = IsPositive(num);

	if (IsPositive(num)) cout << "Positive number" << endl;
	else cout << "Negative number" << endl;

	return 0;
}
