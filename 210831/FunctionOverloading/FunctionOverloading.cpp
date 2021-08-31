#include<iostream>

using namespace std;

// 연산자 오버로딩 방법
// 1. 멤버함수에 의한 연산자 오버로딩
// 2. 전역함수에 의한 연산자 오버로딩

// 동일한 자료형을 대상으로 + 연산자를 전역함수 기반으로,
// 그리고 멤버함수 기반으로 동시에 오버로딩 할 때
// 멤버 함수 기반으로 오버로딩된 함수가 전역함수 기반으로 오버로딩된 함수보다 우선시되어 호출

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	
	friend Point operator+(const Point& pos1, const Point& pos2);
};

Point operator+(const Point& pos1, const Point& pos2)	// operator라는 이름의 함수
{
	cout << "전역함수가 실행되었습니다." << endl;
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

int main()
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();

	return 0;
}