#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// reyhane esmailizadeh 810800004
int main() {
	int o;
	  cin>>o;
	  if(o<0)
	  cout<<"ERORR";
	  if(0<=o && o<=4)
	  cout<<"baby";
	   if(5<=o && o<=11)
	  cout<<"child";
	   if(12<=o && o<=18)
	  cout<<"teenager";
	  if(19<=o && o<=35)  
	  cout<<"young";
	 if(o>=36)
	  cout<<"adult";
	
	return 0;
}
