#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cstdlib>

using namespace std;

struct Node{
	int x, y, link;


};

struct Query{
	int f1, f2, idx;
};
void parse(string, vector<Node>&, vector<int>&);
bool find(int, vector<int>&);
int manhattan(Node,Node);
int main()
{	int n, m, k;
	string junk;
	cin >> n >> m;
	getline(cin,junk);
	vector<Node> farms(n);
	vector<string> mapinfo(m);
	vector<int> l(n, -1);
	farms[0].link = 1;
	l[0] = farms[0].link;
	for (int i =0; i < m; ++i)
	{	
		string input;
		getline(cin, input);
		mapinfo[i] = input;
	}
	cin >> k;
	getline(cin,junk);
	vector<string> queryinfo(k);
	vector<Query> queries(k);
	for(int i = 0; i < k; ++i)
	{
		cin >> queries[i].f1 >> queries[i].f2 >> queries[i].idx;
		getline(cin,junk);
	}
	for(int i = 0; i < m; ++i)
	{
		parse(mapinfo[i], farms, l);
			for(size_t w = 0; w < queries.size(); ++w)
			{
				if(queries[w].idx - 1 == i)
				{
					bool f1exists = find(queries[w].f1, l);
					bool f2exists = find(queries[w].f2, l);

					if(f1exists && f2exists)
					{
						cout << manhattan(farms[queries[w].f1 -1], farms[queries[w].f2 -1]) << endl;
					}
					else
					{
						cout << -1 << endl;
					}
				}
			}

	}


 
   
}

void parse(string mapstring, vector<Node>& farms, vector<int>& l)
{	
	
	int f1, f2, d;
	char dir;
	stringstream st;
	st << mapstring;
	st >> f1 >> f2 >> d >> dir;

	if(f1 == 1 || farms[f1-1].x != 0 || farms[f1-1].y !=0)
	{
		if(dir == 'N')
		{
			farms[f2 - 1].x = farms[f1 -1].x;
			farms[f2 - 1].y = farms[f1 -1].y + d;
		}
		else if(dir == 'E')
		{
			farms[f2 - 1].x = farms[f1 -1].x + d;
			farms[f2 - 1].y = farms[f1 -1].y;
		}
		else if(dir == 'W')
		{
			farms[f2 - 1].x = farms[f1 -1].x - d;
			farms[f2 - 1].y = farms[f1 -1].y;
		}
		else if(dir == 'S')
		{
			farms[f2 - 1].x = farms[f1 -1].x;
			farms[f2 - 1].y = farms[f1 -1].y - d;
		}
		farms[f2 - 1].link = f1;
		l[f2 - 1] = farms[f2 - 1].link;
		
	}
	else if(f2 == 1 || farms[f2-1].x != 0 || farms[f2-1].y != 0)
	{
		if(dir == 'N')
		{
			farms[f1 - 1].x = farms[f2 -1].x;
			farms[f1 - 1].y = farms[f2 -1].y - d;
		}
		else if(dir == 'E')
		{
			farms[f1 - 1].x = farms[f2 -1].x - d;
			farms[f1 - 1].y = farms[f2 -1].y;
		}
		else if(dir == 'W')
		{
			farms[f1 - 1].x = farms[f2 -1].x + d;
			farms[f1 - 1].y = farms[f2 -1].y;
		}
		else if(dir == 'S')
		{
			farms[f1 - 1].x = farms[f2 -1].x;
			farms[f1 - 1].y = farms[f2 -1].y + d;
		}

		farms[f1 -1].link = f2;
		l[f1 -1] = farms[f1 -1].link;
	}

}

bool find(int f, vector<int>& l)
{
	if(f != 1 && l[f-1] == -1) return 0;

	while(f != l[f-1]) f = l[f -1];

	return 1;
}

int manhattan(Node a, Node b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}