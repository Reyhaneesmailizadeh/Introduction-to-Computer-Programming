#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct books{

	string r;
	int sal;
	string name;
};
void moratab1 (books array[],int i)
{
	if(i==1)
	return;
	string temp;
	int j=0;
	while(j<i-1)
	{
		if(array[j].sal>array[j+1].sal)
		{
		swap(array[j],array[j+1]);	
		}
		j++;
	}
	moratab1(array,i-1);
}
void moratab2(books array[],int m)
{
	if(m==1)
	return;
	string temp2;
int j2=0;
while(j2<m-1)
{
	if((array[j2].name).compare(array[j2+1].name)>0)
	{
		swap(array[j2],array[j2+1]);
	}
	j2++;
 } 
 moratab2(array,m-1);
}
void moratab3(books array[], int l)
{
	if(l==1)
	return;
	string temp3;
	int j3=0;
	while(j3<l-1)
	{
		if((array[j3].r).compare(array[j3+1].r)>0)
		{
			swap(array[j3],array[j3+1]);
		}
		j3++;
	}
	moratab3(array,l-1);
}
int main() {
	int n;
	cin>>n;
	books array[n];
	for(int i=0;i<n;i++)
	{
		cin>>array[i].name>>array[i].sal>>array[i].r;
	}
	int p;
	cin>>p;
              if(p==2)
				{
				moratab1(array,n);	
				for(int i=0;i<n;i++)
				cout<<array[i].name<<endl;
				};
			if(p==1)
            {
            	moratab2(array,n);
            	for(int b=0;b<n;b++)
            	cout<<array[b].name<<endl;
			};
			
				if(p==3)
					{
						moratab3(array,n);
						for(int i=0;i<n;i++)
				        cout<<array[i].name<<endl;
					};
				
	
	return 0;
}
