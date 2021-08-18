#include<iostream>

// 존재하는 이름공간이 다르면 동일한 이름의 함수 및 변수 선언이 가능
// 프로젝트의 진행에 있어서 발생할 수 있는 이름 충돌을 막을 목적으로 존재 -> 이름 공간(namespace)

namespace BestComImpl
{
	void SimpleFunc()
	{
		std::cout << "BestCom이 정의한 함수" << std::endl;
	}
}

namespace ProgComImpl
{
	void SimpleFunc()
	{
		std::cout << "ProgCom이 정의한 함수" << std::endl;
	}
}

int main()
{
	BestComImpl::SimpleFunc();	// 이름공간 BestComImpl에 정의된 SimpleFunc의 호출
	ProgComImpl::SimpleFunc();	// 이름공간 ProgComImpl에 정의된 SimpleFunc의 호출
	return 0;
}