#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, numsets = 0;
	cin>>n;
	for(int i = 1; i <= n; ++i)
	{	int sum = 0, j = i;
		while(sum < n)
		{
			sum += j;
			j++;
			if(sum == n) numsets += 1;

		}
	}
	cout<<numsets;
	return 0;
}