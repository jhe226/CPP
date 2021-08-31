#include<iostream>

using namespace std;

// �������� �����ε�
// ������ ����
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
	const Point& operator++(int)	// ��������
	{
		const Point reobj(xpos, ypos);
		xpos += 1;
		ypos += 1;
		return *this;
	}
	friend Point& operator--(Point& ref);
	friend const Point operator--(Point& ref, int);
};

const Point operator--(Point& ref, int)	// ��������
{
	const Point retobj(ref);	// ���̳ʽ� �� ���� �Ұ� -> ��ü ����
	ref.xpos -= 1;
	ref.ypos -= 1;
	return retobj;	// ���̳ʽ� �� ����� ��ü ����
}

int main()
{
	Point pos(3, 5);
	Point cpy;
	cout << "cpy ��ü �ּ� : " << &cpy << endl;
	cpy = pos--;	// [3, 5] ���� �� 1 ���̳ʽ�
	cpy.ShowPosition();		// [3, 5]
	pos.ShowPosition();		// [2, 4]
	cout << "cpy ��ü �ּ� : " << &cpy << endl;

	cpy = pos++;	// [2, 4] ���� �� 1 �÷���
	cpy.ShowPosition(); 	// [2, 4]
	pos.ShowPosition();		// [3, 5]
	cout << "cpy ��ü �ּ� : " << &cpy << endl;

	return 0;
}