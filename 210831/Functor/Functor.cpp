#include<iostream>

using namespace std;

// ()연산자의 오버로딩과 펑터(Functor)
// () 연산자 : 함수의 호출 및 인자 전달에 사용됨 -> () 오버로딩하면 객체를 함수처럼 사용 O
// 펑터 : 함수처럼 동작하는 클래스

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{ }
	// Point 객체에 대한 + 연산자 오버로딩
	Point operator+(const Point& pos) const	// operator라는 이름의 함수
	{
		// Point형 임시 객체 -> 생성과 동시에 반환
		return Point(xpos + pos.xpos, ypos + pos.ypos);
	}
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}
class Adder
{
public:
	// 3개의 () 연산자가 3회 오버로딩
	int operator()(const int& n1, const int& n2)
	{
		return n1 + n2;
	}
	double operator()(const double& e1, const double &e2)
	{
		return e1 + e2;
	}
	Point operator()(const Point& pos1, const Point& pos2)
	{
		return pos1 + pos2;
	}
};

int main()
{
	Adder adder;
	cout << adder(1, 3) << endl;
	cout << adder(1.5, 3.7) << endl;
	cout << adder(Point(3, 4), Point(7, 9)) << endl;

	return 0;
}
