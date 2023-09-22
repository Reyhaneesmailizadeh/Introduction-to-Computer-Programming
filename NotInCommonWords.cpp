#include <iostream>
using namespace std;
#include <string>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
 string al,bl;
 cin>>al>>bl;
 int c=al.size();
 int d=bl.size();
 bool f;
 bool k;
 for(int i=0;i<c;i++)
	{
		f=true;
		for(int j=0;j<d;j++)
		{
			if(al[i]==bl[j])
			{
			f=false;
			break;
			}
		}
        if(f)
        cout<<al[i];
	}
	
	for(int j=0;j<d;j++)
	{
		k=true;
		for(int i=0;i<c;i++)
		{
			if(bl[j]==al[i])
			{k=false;
			break;
			}
		}
		if(k)
		cout<<bl[j];
	}
	
	
	
	
	
	return 0;
}