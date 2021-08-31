#include<iostream>
#include<cstring>

using namespace std;

// ¹è¿­ Å¬·¡½º

class BoundCheckIntArray
{
private:
	int*arr;
	int arrlen;
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int[len];
	}

	int&operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)	// 배열의 범위를 벗어난 경우
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		// 배열을 참조형으로 반환
		return arr[idx];
	}
	~BoundCheckIntArray()
	{
		delete[]arr;
	}
};

int main()
{
	BoundCheckIntArray arr(5);
	
	for (int i = 0; i < 5; i++)
	{
		arr[i] = (i + 1) * 11;
	}

	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << endl;
	}
}
