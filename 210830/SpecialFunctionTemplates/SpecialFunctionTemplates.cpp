#include<iostream>

using namespace std;

// �Լ� ���ø��� Ư��ȭ

template<typename T>
T Max(T a, T b)
{
	return a > b ? a:b;
}

// char * �� �Լ��� �̷��� �����ϴ�, char * �� �Լ��� �ʿ��� ��쿡�� ���� ������ ���� �Լ��� ����϶�

template<>
char * Max(char*a, char*b)
{
	cout << "char*Max<char*>(char*a, char*b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

template<>
// const char*Max<const char*>(const char*a, const char*b)
const char*Max(const char*a, const char*b)
{
	cout << "const char*Max<const char*>(const char*a, const char*b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}

int main()
{
	cout << Max(11, 15) << endl;
	cout << Max('T', 'O') << endl;
	cout << Max(3.5, 7.5) << endl;
	
	// str1�� str2�� ���� ���·� ���� -> str1�� str2�� �������� : char *
	char str1[] = "Simple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl;

	// ���ڿ��� ����(���)���� ���� ��ȯ�Ǵ� �ּҰ��� ������ ���� const char*�̴�
	cout << Max("Simple", "Best") << endl;

	return 0;

}