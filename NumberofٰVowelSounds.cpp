#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	string a;
	cin>>a;
	int c=a.size();
	string b;
	b="oieau";
	int i=0;
	int count=0;
	while(i<c)
	{
		
		for(int j=0;j<5;j++)
		{
			if(a[i]==b[j])
			count++;
		}
		i++;
	}
	cout<<count;
	return 0;
}
