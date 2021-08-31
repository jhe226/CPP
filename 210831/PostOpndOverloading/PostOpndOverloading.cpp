#include<iostream>

using namespace std;

// 후위연산 오버로딩
// 전위와 후위
// ++pos -> pos.operator++()
// pos++ -> pos.operator++(int)
// --pos -> pos.operator--()
// pos-- -> pos.operator--(int)

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
	const Point& operator++(int)	// 전위증가
	{
		const Point reobj(xpos, ypos);
		xpos += 1;
		ypos += 1;
		return *this;
	}
	friend Point& operator--(Point& ref);
	friend const Point operator--(Point& ref, int);
};

const Point operator--(Point& ref, int)	// 후위감소
{
	const Point retobj(ref);	// 마이너스 후 리턴 불가 -> 객체 복사
	ref.xpos -= 1;
	ref.ypos -= 1;
	return retobj;	// 마이너스 전 복사된 객체 리턴
}

int main()
{
	Point pos(3, 5);
	Point cpy;
	cout << "cpy 객체 주소 : " << &cpy << endl;
	cpy = pos--;	// [3, 5] 복사 후 1 마이너스
	cpy.ShowPosition();		// [3, 5]
	pos.ShowPosition();		// [2, 4]
	cout << "cpy 객체 주소 : " << &cpy << endl;

	cpy = pos++;	// [2, 4] 복사 후 1 플러스
	cpy.ShowPosition(); 	// [2, 4]
	pos.ShowPosition();		// [3, 5]
	cout << "cpy 객체 주소 : " << &cpy << endl;

	return 0;
}