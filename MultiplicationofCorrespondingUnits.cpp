#include <iostream>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main() {
	int x[5];
	for(int i=0;i<5;i++)
	cin>>x[i];
	int y[5];
	for(int i=0; i<5;i++)
	{cin>>y[i];
	
	}
	int z[5];
	for(int i=0; i<5; i++)
	z[i]=x[i]*y[i];
	
	for(int i=0; i<5; i++)
	cout<<z[i]<<" ";
	return 0;
}
