#include<iostream>

// �̸� ���� ����� �Լ� ����� ������ �и�

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
	// :: -> ���� ���� ������
	BestComImpl::SimpleFunc();	// �̸����� BestComImpl�� ���ǵ� SimpleFunc�� ȣ��
	ProgComImpl::SimpleFunc();	// �̸����� ProgComImpl�� ���ǵ� SimpleFunc�� ȣ��
	return 0;
}

void BestComImpl::SimpleFunc()
{
	std::cout << "BestCom�� ������ �Լ�" << std::endl;
}

void ProgComImpl::SimpleFunc()
{
	std::cout << "ProgCom�� ������ �Լ�" << std::endl;
}