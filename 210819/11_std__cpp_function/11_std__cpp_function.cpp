#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<cstdio>
#include<cstring>

// C++에서 C언어의 표준 함수 호출하기
// .h 생략하고 앞에 c를 붙여주면 C언어에 대응하는 C++ 헤더 파일의 이름이 된다.

using namespace std;

int main()
{
	char str1[] = "Result";
	char str2[30];

	strcpy(str2, str1);
	printf("%s : %f\n", str1, sin(0.14));
	printf("%s : %f\n", str1, abs(-1.25));

	return 0;
}