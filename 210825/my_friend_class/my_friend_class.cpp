#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

// Ŭ������ firen ����
// friend ������ private ����� ������ ����ϴ� ����
// ���� ���п� ���ϴ� ���� -> �ſ� ���������� ����Ǿ�� ��

class Girl;

class Boy
{
private:
	int height;
	friend class Girl;	// Girl Ŭ������ ���� friend ���� -> ���ٿ� ���� ���� �ο�
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