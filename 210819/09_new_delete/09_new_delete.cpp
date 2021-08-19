#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

// new & delete

char *MakeStrAdr(int len)
{
	// malloc을 대신하는 메모리의 동적 할당 방법
	// 크기를 바이트 단위로 계산하는 일을 거치지 않아도 된다.

	// char*str = (char*)malloc(sizeof(char)*len);
	char * str = new char[len];

	return str;
}

int main()
{
	char*str = MakeStrAdr(20);
	strcpy(str, "I am so happy");
	cout << str << endl;

	// free를 대신하는 메모리 해제 방법
	// new 연산자로 할당된 메모리 공간은 반드시 delete 함수 호출을 통해 소멸해야한다.

	//free(str);
	delete[]str;	// 배열 소멸

	return 0;
}