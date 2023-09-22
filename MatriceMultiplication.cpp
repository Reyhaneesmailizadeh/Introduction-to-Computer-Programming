#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


typedef int Matrix[2][4];
void addition(Matrix A, Matrix B, Matrix C)
{
  for(int j=0;j<2;j++)
  {
    for(int i=0;i<4;i++)
    C[j][i]=A[j][i]*B[j][i];
  };
};



int main() {
	Matrix A;
	for(int j=0;j<2;j++)
	{
		for(int i=0;i<4;i++)
		cin>>A[j][i];
	}
	Matrix B;
	for(int j=0;j<2;j++)
	{
		for(int i=0;i<4;i++)
		cin>>B[j][i];
	}
	Matrix C;
	addition(A,B,C);
	for(int j=0;j<2;j++)
	{
		for(int i=0;i<4;i++)
		cout<<C[j][i]<<" ";
		cout<<endl;
	}
	return 0;
}
