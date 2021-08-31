#include<iostream>

using namespace std;

// 연산자 오버로딩

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0):xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	Point operator+(const Point&ref)	// operator라는 이름의 함수
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
};

int main()
{
	Point pos1(3, 4);
	Point pos2(10, 20);

	// pos1 객체의 멤버함수 operator+를 호출하면서 인자로 pos2 객체 전달
	// -> 두 객체의 멤버별 덧셈결과로 새로운 Point 객체가 만들어지고
	// 이것이 반환되어 pos3를 초기화.(이 과정에서 복사 생성자 호출)

	Point pos3 = pos1.operator+(pos2);

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();

	return 0;
}