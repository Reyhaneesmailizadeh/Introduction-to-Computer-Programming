#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double BMI(double x, double y)
{
double z=x/100;
double f=y/(z*z);
	return f;
	
}

int main() {
	cout.precision(1);
	double x,y;
	cin>>x>>y;
	if(BMI(x,y)<20)
	cout<<fixed<<BMI(x,y)<<endl<<"underweight";
	if(BMI(x,y)>=20 && BMI(x,y)<=24.9)
	cout<<fixed<<BMI(x,y)<<endl<<"normal";
	if(BMI(x,y)>=25 && BMI(x,y)<=29.9)
	cout<<fixed<<BMI(x,y)<<endl<<"overweight";
	if(BMI(x,y)>=30 && BMI(x,y)<=34.9)
	cout<<fixed<<BMI(x,y)<<endl<<"obese";
	if(BMI(x,y)>=35)
	cout<<fixed<<BMI(x,y)<<endl<<"extremely obese";
	return 0;
}
