#include<iostream>
#include<string>
#include<vector>

using namespace std;


size_t InsertionIndex(vector<int>& v, int d)
{
	for(size_t i = 0; i < v.size(); ++i)
	{
		if(d < v[i])
		{
			return i;
		}
	}
	return v.size();
}


int main()
{	
	int n, m;
	
	cin >> n >> m;
	vector<string> sortedstrings;
	vector<int> sorteddisorder;
	string junk;
	getline(cin, junk);
	int disorder = 0;
	for(int i = 0; i < m; ++i)
	{	string input;
		getline(cin, input);
		int disorder = 0;
		for(int j = 0; j < n; ++j)
		{
			for(int k = j; k < n; ++k)
			{
				if(int(input[j]) > int(input[k]))
				{
					disorder += 1;

				}
			}
		}

		size_t l = InsertionIndex(sorteddisorder, disorder);
		sorteddisorder.insert(sorteddisorder.begin() + l, disorder);
		sortedstrings.insert(sortedstrings.begin() + l, input);
		


	}
	

	for(size_t i = 0; i < sortedstrings.size(); ++i)
	{
		cout << sortedstrings[i]<<endl;
		
	}

	return 0;
}