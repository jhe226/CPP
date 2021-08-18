#include<iostream>

// �Լ� �����ε�
/*
   C++�� �Լ� ȣ�� �� '�Լ��� �̸�'�� '���޵Ǵ� ������ ����'�� ���ÿ� â���Ͽ� ȣ���� �Լ��� ������
   ���� �Ű������� ������ �ٸ��ٸ� ������ �̸��� �Լ��� ���� ����.
   ���� �̷��� ������ �Լ� ���Ǹ� ������ '�Լ� �����ε�(Function Overloading)'�̶� �Ѵ�.
*/

/*
   �Ű������� �ڷ���, �Ű������� ���� �ٸ��Ƿ� �����ε� ����.
   ��ȯ���� ���� -> �����ε� ���� ���� X
*/

void Myfunc()
{
	std::cout << "Myfunc(void) called" << std::endl;
}

void Myfunc(char c)		// �Ű����� �ڷ����� �ٸ�
{
	std::cout << "Myfunc(char c) called" << std::endl;
}

void Myfunc(int a)		// �Ű����� ���� �ٸ�
{
	std::cout << "Myfunc(int a) called" << std::endl;
}

void Myfunc(int a, int b)		// �Ű����� ���� �ٸ�
{
	std::cout << "Myfunc(int a, int b) called" << std::endl;
}

int main()
{
	Myfunc();
	Myfunc('A');
	Myfunc(12, 13);

	return 0;
}