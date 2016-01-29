#include<iostream>
#include<map>
#include<string>
#include<cstdio>

using namespace std;

int main()
{
	string tree;
	map<string,float> treeMap;
	float i = 0;
	while(getline(cin,tree))
	{	
		++i;
		
		map<string,float>::iterator itr = treeMap.find(tree);
		if(itr == treeMap.end())
		{
			treeMap[tree] = 1;
		}
		else
		{
			treeMap[tree] += 1;
		}

	
	}

	map<string, float>::iterator stop = treeMap.end();

	for(map<string, float>::iterator itr = treeMap.begin(); itr != stop; ++itr)
	{

		
		printf("%s %.4f\n", itr->first.c_str(), (itr->second)*100.0/i);


	}

}