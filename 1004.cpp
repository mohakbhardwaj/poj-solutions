#include<iostream>

using namespace std;

int main(void)
{	float input, average = 0;

	for(int i = 0; i < 12; ++i)
	{
		cin>>input;
		average += input/12.0;
	}
	cout<<'$'<<average<<endl;
}