#include<iostream>

namespace Hybrid
{
	void HybFunc()
	{
		std::cout << "So simple Function!" << std::endl;
		std::cout << "In namespace Hybrid!" << std::endl;
	}

}

int main()
{
	// using을 이용해서 '이름공간 Hybrid에 정의된 HybFunc를 호출할 때에는 이름공간을 지정하지 않고 사용하겠다'는 선언

	using Hybrid::HybFunc;
	HybFunc();	// using 선언을 통해 이름공간의 지정 없이 HybFunc 함수를 호출
	return 0;
}
