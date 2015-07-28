#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;

int Input(){  
    char cha;  
    int x=0;  
    while(cha=getchar())  
        if(cha >= 48 && cha < 58) break;  
    x=cha-48;
    while(cha=getchar()) {  
        if(cha < 48 || cha >= 58) break;  
        x=x*10+cha-48;  
    }  
    return x;
}

int main(){
	int test_num;
	cin>>test_num;
	int r, c;
	int i, j;
	int rline[2001], cline[2001];
	int rans[2001], cans[2001];
	long long left, right, ans;	int ansr, ansc, diff;
	
	int count = 0;
	while(test_num--){
		r = Input();
		c = Input();
		long long all = 0;
		long long rsum = 0;
		long long csum = 0;
		memset(rline, 0, sizeof(int) * r);
		memset(cline, 0, sizeof(int) * c);
		
		int in;
		for(i = 0; i < r; i++)
			for(j = 0; j < c; j++){
				in = Input();
				rline[i] += in;
				cline[j] += in;
			}
		
		for(i = 0; i < r; i++){
			rsum += rline[i] * i;
			all += rline[i];
		}
		for(i = 1; i < c; i++)
			csum += cline[i] * i;
			
		ans = 0;	ansr = -1;	ansc = -1;
		left = 0;	right = all - rline[0];
		
		ans += rsum;
		rans[0] = ans;
		int realindex = 0; long long realvalue  = rans[0];
		for(i = 0; i < r-1; i++){
			left += rline[i];
			
			diff = left - right;
			
			rans[i+1] = rans[i] + diff;
			if(rans[i+1] < realvalue){
				realindex = i+1;
				realvalue = rans[i+1];
			}
			right -= rline[i+1];
		}
		ansr = realindex;
		ans = realvalue;
				
		left = 0;		right = all - cline[0];
		ans += csum;
		cans[0] = ans;
		realindex = 0; realvalue  = cans[0];
		for(i = 0; i < c-1; i++){
			left += cline[i];
			
			diff = left - right;
			cans[i+1] = cans[i] + diff;
			if(cans[i+1] < realvalue){
				realindex = i+1;
				realvalue = cans[i+1];
			}
				
			right -= cline[i+1];
		}
		ansc = realindex;
		ans = realvalue;
		
		printf("%d %d\n%lld\n", ansr+1, ansc+1, ans*100);
	}
	return 0;
}