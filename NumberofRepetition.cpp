#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main() {
char y[20];
  for(int i=0;i<20;i++)
  cin>>y[i];
  char x;
  cin>>x;
  int count=0;
  int n=0;
  while(n<20)
  {
    if(y[n]==x)
    count++;
    
    n++;
  }
 
  if(count==0)
  cout<<"not found";
  else
  cout<<count;
  return 0;
}
	
	
	
	
