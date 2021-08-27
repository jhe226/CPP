#include<iostream>

using namespace std;

// 가상함수(virtual function)


class First
{
public:
	virtual void MyFunc()
	{
		cout << "First MyFunc" << endl;
	}

};

class Second : public First
{
public:
	virtual void MyFunc()
	{
		cout << "Second MyFunc" << endl;
	}
};

class Third : public Second
{
public:
	virtual void MyFunc()
	{
		cout << "Third MyFunc" << endl;
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

	cout << fptr << ", " << sptr << ", " << tptr;

	delete tptr;
	return 0;

}