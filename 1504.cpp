#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<numeric>
#include<iterator>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string junk;
	getline(cin, junk);
	for(int i =0; i < n; ++i)
	{	string str;
		stringstream s;

		getline(cin, str);
		reverse_copy(str.begin(), str.end(), ostream_iterator<char>(s));
		int k, sum = 0;
		while(s >> k)
		{
			sum += k;
		}
		int j = 0, rem;
		while(sum > 0)
		{
			
			rem = sum%10;
			j = j*10 + rem;
			sum = sum/10;

		}
		cout << j << endl;
		

	}

	return 0;
}