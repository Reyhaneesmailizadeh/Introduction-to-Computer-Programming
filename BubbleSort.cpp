#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool entekhabi(int a[],int n)
{
  if(n==1)
  return false;
  else
  {
  for(int i=0; i<n;i++)
  {
  	if(a[i]>a[i+1])
  	{
  		int temp;
  		temp=a[i];
  	    a[i]=a[i+1];
	  	a[i+1]=temp;
	 }
  }
  
  entekhabi(a,n-1);
  }
}

int main() {
	
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];
entekhabi(a,n);
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
	return 0;
}
