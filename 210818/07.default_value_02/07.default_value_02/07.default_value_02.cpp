#include<iostream>

// ����Ʈ ���� �Լ��� ���� ��ġ
// �����Ϸ��� �Լ� ����Ʈ ���� �������θ� �˾ƾ� �Լ� ȣ�� ������ ������ ������ �� �� �ִ�.

int Adder(int num1 = 1, int num2 = 2);

int main()
{
	std::cout << Adder() << std::endl;		// 3
	std::cout << Adder(5) << std::endl;		// 7
	std::cout << Adder(3, 5) << std::endl;	// 8
	
	return 0;
}

int Adder(int num1, int num2) {
	return num1 + num2;
}
