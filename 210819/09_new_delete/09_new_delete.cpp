#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

// new & delete

char *MakeStrAdr(int len)
{
	// malloc�� ����ϴ� �޸��� ���� �Ҵ� ���
	// ũ�⸦ ����Ʈ ������ ����ϴ� ���� ��ġ�� �ʾƵ� �ȴ�.

	// char*str = (char*)malloc(sizeof(char)*len);
	char * str = new char[len];

	return str;
}

int main()
{
	char*str = MakeStrAdr(20);
	strcpy(str, "I am so happy");
	cout << str << endl;

	// free�� ����ϴ� �޸� ���� ���
	// new �����ڷ� �Ҵ�� �޸� ������ �ݵ�� delete �Լ� ȣ���� ���� �Ҹ��ؾ��Ѵ�.

	//free(str);
	delete[]str;	// �迭 �Ҹ�

	return 0;
}