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
	// using�� �̿��ؼ� '�̸����� Hybrid�� ���ǵ� HybFunc�� ȣ���� ������ �̸������� �������� �ʰ� ����ϰڴ�'�� ����

	using Hybrid::HybFunc;
	HybFunc();	// using ������ ���� �̸������� ���� ���� HybFunc �Լ��� ȣ��
	return 0
}