#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int a;
	int z;
	int m=1;
	cin>>a;
	int max1=0;
	int max2=0;
	while(a!=-1){
		if(a>=max1)
		{
			max2=max1;
			max1=a;
			z=m;
		}
		else if(a<max1)
		{ max1=max1;
		if(a>=max2)
		max2=a;
          


		}
		m+=1;
		cin>>a;
	}
	
	cout<<z<<" "<<max1<<" "<<max2;
	
	
	return 0;
}
