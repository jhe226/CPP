#include<iostream>

// 이름 공간 기반의 함수 선언과 정의의 분리

namespace BestComImpl
{
	void SimpleFunc();
}

namespace ProgComImpl
{
	void SimpleFunc();
}

int main()
{
	// :: -> 범위 지정 연산자
	BestComImpl::SimpleFunc();	// 이름공간 BestComImpl에 정의된 SimpleFunc의 호출
	ProgComImpl::SimpleFunc();	// 이름공간 ProgComImpl에 정의된 SimpleFunc의 호출
	return 0;
}

void BestComImpl::SimpleFunc()
{
	std::cout << "BestCom이 정의한 함수" << std::endl;
}

void ProgComImpl::SimpleFunc()
{
	std::cout << "ProgCom이 정의한 함수" << std::endl;
}