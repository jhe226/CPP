#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

// 클래스 템플릿의 특수화
// 특정 자료형을 기반으로 생성된 객체에 대해 구분이 되는 다른 행동 양식을 적용하기 위함

template <typename T>
class Point
{
private:
	T xpos, ypos;
public:
	// 일반적인 클래스처럼 매개변수의 디폴트 값은 클래스 템플릿 내에서만 표현
	Point(T x = 0, T y = 0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

// 클래스 템플릿 SimpleDataWrapper가 정의
// 간단히 하나의 데이터를 저장, 이 데이터에 담긴 정보 출력하도록 정의
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

// 클래스 템플릿 SimpleDataWrapper을 Point<int>형에 대해 특수화
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
	// int형에 대해서는 특수화 진행 X -> 아래 문장이 컴파일 될 때 SimpleDataWrapper <int>가 만들어지고,
	// 이 클래스를 기반으로 객체 생성
	SimpleDataWrapper<int>iwrap(170);
	iwrap.ShowDataInfo();

	// char* 형에 대해서 특수화 진행 O -> 별도의 템플릿 클래스 생성 X, 미리 정의된 템플릿 클래스 객체가 생성
	char arr[] = "Class Template Specialization";
	SimpleDataWrapper<char *> swrap(arr);
	swrap.ShowDataInfo();
	
	// Point<int> 형에 대해서 특수화 진행 O -> 별도의 템플릿 클래스 생성 X, 미리 정의된 템플릿 클래스 객체가 생성
	SimpleDataWrapper<Point<int>> poswrap(3, 7);
	poswrap.ShowDataInfo();
	return 0;
}