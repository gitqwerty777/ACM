#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

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
	int n;
	cin>>n;
	
	long long a, b; long long rate;
	cout<<fixed<<setprecision(2);
	int count = 0;
	while(n--){
		cin>>a>>b;
		
		rate = (b-a)*100000 / a;
		
		if(rate <= 4 && rate >= -4){
			cout<<"0.00% keep"<<endl;
			continue;
		}
		
		if(rate < 0){
			rate -= rate;
			cout<<"-";
		}
		if(rate % 10 >= 5)
			rate += 10;
			
		int fl = (rate % 1000) / 10;
		if(fl < 10)
			cout<<rate/1000<<".0"<<fl;
		else
			cout<<rate/1000<<"."<<fl;
		
		rate /= 1000;
		if(rate >= 10 || rate <= -7)
			cout<<"% dispose"<<endl;
		else
			cout<<"% keep"<<endl;
	}
	
	
	return 0;
}