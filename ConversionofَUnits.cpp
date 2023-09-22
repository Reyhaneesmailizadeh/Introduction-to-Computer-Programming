#include <iostream>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double ab(double x)
{
double a= 9*(x-273)/5+32;
return a;	
}
double bc(double x){
	double b=5*(x-32)/9+273;
	return b;
}
double cd(double x){
	double c=9*x/5+32;
	return c;
}
double df(double x){
	double d=5*(x-32)/9;
	return d;
}
double fg(double x){
	double f=x-273;
	return f;
}
double gh(double x){
	double g=x+273;
	return g;
}


int main() {
cout.precision(1);
double x;
char a,b;
cin>>x>>a>>b;

if(a=='K' && b=='F')
cout<<fixed<<ab(x);
if(a=='F'&&b=='K')
cout<<fixed<<bc(x);
if(a=='C' && b=='F')
cout<<fixed<<cd(x);
if(a=='F'&&b=='C')
cout<<fixed<<df(x);
if(a=='K'&& b=='C')
cout<<fixed<<fg(x);
if(a=='C' && b=='K')
cout<<fixed<<gh(x);


	return 0;
}

