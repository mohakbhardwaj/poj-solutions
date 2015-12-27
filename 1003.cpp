#include<iostream>

using namespace std;
int main()
{	
	while(true)
	{
		float input,sum=0.00;
		int numcards = 0;
		cin >> input;
		if(input==0.00)
		{
			
			return 0;
		}
		while(input - sum > 0.00)
		{
			++numcards;
			sum += 1.0/(numcards + 1.0);

		}
		cout << numcards << " card(s)\n";
		
	}
	
}