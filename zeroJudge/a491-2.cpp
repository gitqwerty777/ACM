#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int test_num;
	cin>>test_num;
	int r, c;
	int i, j;
	string ans;
	
	while(test_num--){
		scanf("%d %d", &r, &c);
		
		long long rsum = 0;
		long long csum = 0;
		long long all = 0;
		vector<int> rline(r);
		vector<int> cline(c);
		vector<long long> rlinelsum(r);
		vector<long long> clinelsum(c);
		
		
		int in;
		for(i = 0; i < r; i++)
			for(j = 0; j < c; j++){
				scanf("%d", &in);
				rsum += in * i;
				csum += in * j;
				rline[i] += in;
				cline[j] += in;
				all += in;
			}
		
		long long left = 0, right = 0, ans = 0; int ansr, ansc;
		int diff;
		right = all - rline[0] - rline[1];
		for(i = 1; i < r; i++)
			ans += rline[i] * i;
		for(i = 0; i < r-1; i++){
			diff = left + rline[i] - rline[i+1] - right;
			if(diff < 0)
				ans += diff;
			else{
				ansr = i;break;}
			
			ansr = i;//ok?
			left += rline[i];
			right -= rline[i+1];
		}
		
		left = 0;
		right = all - cline[0] - cline[1];
		for(i = 1; i < c; i++)
			ans += cline[i] * i;
		for(i = 0; i < c-1; i++){
			diff = left + cline[i] - cline[i+1] - right;
			if(diff < 0)
				ans += diff;
			else{
				ansc = i;break;}
			
			left += cline[i];
			right -= cline[i+1];
		}
		ansc = i;
		
		printf("%d %d\n%lld\n", ansr+1, ansc+1, ans*100);
	}
	return 0;
}