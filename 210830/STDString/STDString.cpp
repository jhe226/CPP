#include<iostream>
#include<string>

using namespace std;

// string은 문자열을 처리하기 위해 정의된 클래스
// 클래스의 사용을 위해 헤더파일 <string>을 포함해야 한다

int main()
{
	string str1 = "I like ";
	string str2 = "string class";

	// string 객체간 덧셈 연산 가능
	// operator + 의 오버로딩 가능
	string str3 = str1 + str2;

	// string 클래스가 << 연산자에 대해서도 오버로딩
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3) cout << "동일 문자열입니다" << endl;
	else cout << "동일하지 않은 문자열입니다" << endl;

	string str4;
	cout << "문자열 입력 : ";
	cin >> str4;
	cout << "입력한 문자열 : " << str4 << endl;

	return 0;

}