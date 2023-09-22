#include <iostream>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int majmooeadad(int n)
{ 
int z;
int sum=0;
	while(n!=0){
		z=n%10;
		sum+=z;
		n=n/10;
		
	}
	return sum;
}


int main(){
	int n;
	cin>>n;
	if(majmooeadad(n)%2==0)
	
cout<<"Even";
if(majmooeadad(n)%2==1)
cout<<"Odd";
return 0;
}
