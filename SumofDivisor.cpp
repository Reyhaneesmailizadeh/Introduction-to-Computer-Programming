#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int n;
	cin>>n;
	int a=1;
	int b=1;
	if(n==1)
	cout<<"1";
	else{
	
	cout<<a<<" "<<b<<" ";
	int i=3;
	while(i<=n){
		int c;
		c=a+b;
		cout<<c<<" ";
		a=b;
		b=c;
	i+=1;	
	}
	}
	return 0;
}
