#include<iostream>

// �����ϴ� �̸������� �ٸ��� ������ �̸��� �Լ� �� ���� ������ ����
// ������Ʈ�� ���࿡ �־ �߻��� �� �ִ� �̸� �浹�� ���� �������� ���� -> �̸� ����(namespace)

namespace BestComImpl
{
	void SimpleFunc()
	{
		std::cout << "BestCom�� ������ �Լ�" << std::endl;
	}
}

namespace ProgComImpl
{
	void SimpleFunc()
	{
		std::cout << "ProgCom�� ������ �Լ�" << std::endl;
	}
}

int main()
{
	BestComImpl::SimpleFunc();	// �̸����� BestComImpl�� ���ǵ� SimpleFunc�� ȣ��
	ProgComImpl::SimpleFunc();	// �̸����� ProgComImpl�� ���ǵ� SimpleFunc�� ȣ��
	return 0;
}