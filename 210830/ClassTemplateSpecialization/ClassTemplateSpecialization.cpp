#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

// Ŭ���� ���ø��� Ư��ȭ
// Ư�� �ڷ����� ������� ������ ��ü�� ���� ������ �Ǵ� �ٸ� �ൿ ����� �����ϱ� ����

template <typename T>
class Point
{
private:
	T xpos, ypos;
public:
	// �Ϲ����� Ŭ����ó�� �Ű������� ����Ʈ ���� Ŭ���� ���ø� �������� ǥ��
	Point(T x = 0, T y = 0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

// Ŭ���� ���ø� SimpleDataWrapper�� ����
// ������ �ϳ��� �����͸� ����, �� �����Ϳ� ��� ���� ����ϵ��� ����
template <typename T>
class SimpleDataWrapper
{
private:
	T mdata;
public:
	SimpleDataWrapper(T data) : mdata(data)
	{ }
	void ShowDataInfo(void)
	{
		cout << "Data : " << mdata << endl;
	}
};

template <>
class SimpleDataWrapper <char*>
{
private:
	char*mdata;
public:
	SimpleDataWrapper(char*data)
	{
		
	}

	void ShowDataInfo(void)
	{
		cout << "String : " << mdata << endl;
		cout << "Length : " << strlen(mdata) << endl;
	}

	~SimpleDataWrapper()
	{
		delete[]mdata;
	}
};

// Ŭ���� ���ø� SimpleDataWrapper�� Point<int>���� ���� Ư��ȭ
template <>
class SimpleDataWrapper <Point<int>>
{
private:
	Point<int> mdata;
public:
	SimpleDataWrapper(int x, int y) : mdata(x, y)
	{ }

	void ShowDataInfo()
	{
		mdata.ShowPosition();
	}
};

int main()
{
	// int���� ���ؼ��� Ư��ȭ ���� X -> �Ʒ� ������ ������ �� �� SimpleDataWrapper <int>�� ���������,
	// �� Ŭ������ ������� ��ü ����
	SimpleDataWrapper<int>iwrap(170);
	iwrap.ShowDataInfo();

	// char* ���� ���ؼ� Ư��ȭ ���� O -> ������ ���ø� Ŭ���� ���� X, �̸� ���ǵ� ���ø� Ŭ���� ��ü�� ����
	char arr[] = "Class Template Specialization";
	SimpleDataWrapper<char *> swrap(arr);
	swrap.ShowDataInfo();
	
	// Point<int> ���� ���ؼ� Ư��ȭ ���� O -> ������ ���ø� Ŭ���� ���� X, �̸� ���ǵ� ���ø� Ŭ���� ��ü�� ����
	SimpleDataWrapper<Point<int>> poswrap(3, 7);
	poswrap.ShowDataInfo();
	return 0;
}