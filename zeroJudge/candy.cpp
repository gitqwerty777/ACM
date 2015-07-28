#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <iomanip>
int input()   
{   
  char cha;   
  unsigned long long int x=0,flag=1;   
  while(cha=getchar())   
     if(cha!=' '&&cha!='\n') break;   
   if(cha!='-')
       x=x*10+cha-48;  
   else flag=-1;   
  while(cha=getchar())    
    {   
     if(cha==' '||cha=='\n') break;   
      x=x*10+cha-48;   
    }   
    return x*flag;   
}


using namespace std;

int main(){
	int n, q;
	n = input();
	q = input();
	
	int 
	for(int i=0; i < n; i++){
		input();
	}
	
	
	return 0;
}