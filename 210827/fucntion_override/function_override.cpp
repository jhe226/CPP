#include<iostream>

using namespace std;

class First
{
public:
	void MyFunc()
	{
		cout << "First MyFunc" << endl;
	}
	void FirstFunc()
	{
		cout << "FirstFunc" << endl;
	}
};

class Second : public First
{
public:
	void MyFunc()
	{
		cout << "Second MyFunc" << endl;
	}
	void SecondFunc()
	{
		cout << "SecondFunc" << endl;
	}
};

class Third : public Second
{
public:
	void MyFunc()
	{
		cout << "Third MyFunc" << endl;
	}
	void ThirdFunc()
	{
		cout << "ThirdFunc" << endl;
	}
};

int main()
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();

	fptr->FirstFunc();
	sptr->SecondFunc();
	tptr->ThirdFunc();

	cout << fptr << ", " << sptr << ", " << tptr;

	delete tptr;
	return 0;

}