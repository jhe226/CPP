#include<iostream>	// ������� ����

// C������ ��� ��� ���� ���������� �޸�������
// C++������ �ش� ������ ���ʿ��ϴ�.

int main() {
	
	// ��� �⺻����  std::cout<< '��´��1' << '��´��2' << '��´��3';
	// cout : �Լ�X, ��ü
	// << : ��� ������
	// std::endl��� : ����

	int num = 20;
	std::cout << "Hello World" << std::endl;
	std::cout << "Hello " << "World" << std::endl;
	std::cout << num << ' ' << 'A';
	std::cout << ' ' << 3.14 << std::endl;

	return 0;
}