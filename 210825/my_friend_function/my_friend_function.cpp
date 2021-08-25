#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

class PointOP
{
private:
	int opcnt;
public:
	PointOP(): opcnt(0) 
	{ }
	Point PointAdd(const Point&, const Point&);		// Point Ŭ������ friend �Լ� �κ� ������ �̸� ����
	Point PointSub(const Point&, const Point&);
	~PointOP()
	{
		cout << "Operation times: " << opcnt << endl;
	}
};

class Point
{
private:
	int x;
	int y;
public:
	Point(const int& xpos, const int& ypos): x(xpos), y(ypos)
	{ }
	// �Լ��� friend ����

	// �̷��� Ŭ������ Ư�� ��� �Լ��� ������ε� friend ������ �����ϴ�.
	friend Point PointOP::PointAdd(const Point&, const Point&);		// �ٸ� Ŭ������ ��� �Լ�
	friend Point PointOP::PointSub(const Point&, const Point&);
	friend void ShowPointPos(const Point&);		// ���� �Լ�, ������ ���ҵ� ��
};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2)
{
	opcnt++;
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);		// private ��� ����, friend ����� �Լ��� ����
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2)
{
	opcnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}

int main()
{
	Point pos1(1, 2);
	Point pos2(2, 4);
	PointOP op;

	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos2, pos1));

	return 0;
}

void ShowPointPos(const Point& pos)		// friend �������� ���� ������ �ʿ� X
{
	// private ��� ����
	cout << "x : " << pos.x << ", ";
	cout << "y : " << pos.y << endl;
}