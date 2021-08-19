#include<iostream>
#include<stdlib.h>

using namespace std;

class Simple
{
public:
	Simple()	// 积己磊
	{
		cout << "I'm a simple constructor" << endl;
	}
};

int main()
{
	cout << "case 1 : ";
	Simple *sp1 = new Simple;	// 积己磊 角青

	cout << "case 2 : ";
	Simple *sp2 = (Simple*)malloc(sizeof(Simple)*1);	// 积己磊 角青
	
	cout << endl << "end of main" << endl;
	delete sp1;
	free(sp2);

	return 0;
}
