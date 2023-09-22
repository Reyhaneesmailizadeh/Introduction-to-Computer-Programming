#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void swap(int arrayn[])
{
      int *ptrnl;
    	ptrnl=arrayn;
    	 int templ=*(ptrnl+0);
    	*(ptrnl)=*(ptrnl+1);
    	*(ptrnl+1)=templ;
    	cout<<*(ptrnl)<<" "<<*(ptrnl+1);
}

int main() 
{
	int arrayn[2];
	for(int ii=0;ii<2;ii++)
	cin>>arrayn[ii];
	swap(arrayn);
	return 0;
}
