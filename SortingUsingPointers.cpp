

#include <iostream>
using namespace std;

void hobab( int a[],int n)
{  

     if(n==1)
     return;
       int *ptrml;
       ptrml=a;
     int templk;
      int i=0;
     while(i<n-1) 
    {
    if(*(ptrml+i)>*(ptrml+i+1))
    {
         templk=*(ptrml+i);
      *(ptrml+i)=*(ptrml+i+1);
       *(ptrml+i+1)=templk;  
    }
    i++;
     }
  hobab(a,(n-1));
}

int main() {
  int n;
  cin>>n;
  int *a=new int[n];
  int *ptr1ml=a;
  for(int i=0;i<n;i++)
  cin>>a[i];
  hobab(a,n);
  for(int i=0;i<n;i++)
  cout<<*(ptr1ml+i)<<" ";
  
  
  
  return 0;
}
