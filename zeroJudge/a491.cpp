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
		
		vector<int> rsum(r);
		vector<int> csum(c);
		
		int in;
		for(i = 0; i < r; i++)
			for(j = 0; j < c; j++){
				scanf("%d", &in);
				rsum[i] += in;
				csum[j] += in;
			}
			
		long long left = 0, right = 0;
		int indexl = 0, indexr = r-1;
		int ansr, ansc;
		long long costr, costc;
		
		while(indexl < indexr){
			if(left >= right)
				while(indexl < indexr && left >= right)
					right += rsum[indexr--];
			else
				while(indexl < indexr && left < right)
					left += rsum[indexl++];
		}
		ansr = indexl;
		costr = left + right - rsum[indexl]*2;
		
		left = 0; 	right = 0;
		indexl = 0; indexr = c-1;
		
		while(indexl < indexr){
			if(left >= right)
				while(indexl < indexr && left >= right)
					right += csum[indexr--];
			else
				while(indexl < indexr && left < right)
					left += csum[indexl++];
		}		
		ansc = indexl;
		costc = left + right - csum[indexl]*2;
		
		printf("%d %d\n%lld\n", ansr, ansc, (costr+costc)*100);
	}
	return 0;
}