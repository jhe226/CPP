#include<iostream>

// scanf�� ����ϴ� �������� �Է�
// ��¿����� ���������� �Է¿����� ������ ���� ������ ���ʿ���

int main() {

	// �Է��� �⺻ ���� std::cin >> '����'
	// cin�� �Լ��� �ƴ� ��ü, >>�� �Է� ������

	int val1;
	std::cout << "ù ��° �����Է� : ";
	std::cin >> val1;

	int val2;
	std::cout << "�� ��° �����Է� : ";
	std::cin >> val2;

	int result = val1 + val2;
	std::cout << "���� ��� : " << result << std::endl;

	return 0;
}