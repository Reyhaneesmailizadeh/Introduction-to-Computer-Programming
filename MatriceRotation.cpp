#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int matris[4][4];
	for(int j=0;j<4;j++)
	{
		for(int i=0;i<4;i++)
		cin>>matris[j][i];
	};
	int temp[4][4];
	for(int j=0;j<4;j++)
	{
		for(int i=0;i<4;i++)
		temp[3-j][3-i]=matris[j][i];
	}
	for(int j=0;j<4;j++)
	{
		for(int i=0;i<4;i++)
		cout<<temp[j][i]<<" ";
		cout<<endl;
	}
	
	return 0;
}
