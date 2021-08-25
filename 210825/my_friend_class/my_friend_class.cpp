#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

// 클래스의 firen 선언
// friend 선언은 private 멤버의 접근을 허용하는 선언
// 정보 은닉에 반하는 선언 -> 매우 제한적으로 선언되어야 함

class Girl;

class Boy
{
private:
	int height;
	friend class Girl;	// Girl 클래스에 대한 friend 선언 -> 접근에 대한 자유 부여
public:
	Boy(int len) : height(len)
	{}
	void ShowYourFriendinfo(Girl& frn);
};

class Girl
{
private:
	char phNum[20];
public:
	Girl(const char* num)
	{
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy& frn);
	friend class Boy;
};

void Boy::ShowYourFriendinfo(Girl &frn)
{
	cout << "Her phone number: " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy &frn)
{
	cout << "Her phone number: " << frn.height << endl;
}

int main()
{
	Boy boy(170);
	Girl girl("010-1234-5678");

	boy.ShowYourFriendinfo(girl);
	girl.ShowYourFriendInfo(boy);
	
	return 0;
}