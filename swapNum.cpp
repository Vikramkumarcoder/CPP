#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cout<<"a: ";
	cin>>a;
	cout<<"b: ";
	cin>>b;
	int c = a;
	a = b;
	b = c;
	cout<<"a: "<<a<<endl;
	cout<<"b: "<<b;
	return 0;
}