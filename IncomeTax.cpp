#include <iostream>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	cout.precision(1);
	double a;
	cin>>a;
	double b;
	cin>>b;
	double p=a-b; 
	if(p<1000)
	cout<<"No tax";
else	if(p>=1000 && p<pow(10,4))
	cout<<fixed<<2*p/100;
else	if(p>=pow(10,4) && p<pow(10,5))
	cout<<fixed<<8*p/100;
else	if(p>=pow(10,5) && p<pow(10,6))
 cout<<fixed<<10*p/100;
	else if(p>=pow(10,6) && p<pow(10,7))
	cout<<fixed<<15*p/100;
else	if(p>=pow(10,7) && p<pow(10,8))
	cout<<fixed<<20*p/100;
else	if(p>=pow(10,8) && p<pow(10,9))
	cout<<fixed<<25*p/100;
else	if( p>=pow(10,9))
	cout<<fixed<<30*p/100;
	return 0;
}
