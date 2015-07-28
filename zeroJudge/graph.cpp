#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
int isort(int a, int b){
	return a > b;
}
int main(){
	vector<int> deg;
	int n;
	
	bool over;
	while(cin>>n && n != 0){
		int i, in;
		long count;
		deg.clear();
		over = false;
		for(i = 0; i < n; i++){
			cin>>in;
			if(in >= n){
				over = true;
				break;}
			count += in;
			deg.push_back(in);
		}
		if(over || count % 2){
			puts("Not possible");
			continue;
		}
		
		sort(deg.begin(), deg.end(), isort);
		deg.insert(deg.begin(), 0);//deg[0] = 0
		
		int lsum = 0, rsum = 0, point = 1, lastadd;
		
		for(int l = n; l > 1; l--){
			if(deg[l] < 1)
				rsum += deg[l];
			else{
				point = l;
				lastadd = 1 * (l-1);
				rsum += lastadd;
				break;
			}
		}
		
		for(int k = 1; k < n; k++){
			lsum += deg[k];
			
			if(point > k){
				rsum -= lastadd;
				while(deg[point] < k && point > k){
					rsum += deg[point];
					point--;
				}
				lastadd = k * (point-k);
				rsum += lastadd;
			}
			if(lsum > k*(k-1) + rsum){
				over = true;
				break;
			}
		}
		
		if(over)
			puts("Not possible");
		else
			puts("Possible");
	}

	return 0;
}