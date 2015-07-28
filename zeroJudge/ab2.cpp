#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <stdlib>

using namespace std;//test getline and cin line

int main(){
	vector<int> ans(4); int n; char dumb; string in; int temp[4]; int a, ab;
	stringstream ss;
	int ten[10], toten[10];
	while(cin>>ans[0]>>ans[1]>>ans[2]>>ans[3]>>n){
		cin>>dumb;//\n
		memset(ten, 0, sizeof(int)*10);
		memset(toten, 0, sizeof(int)*10);
		a = 0; ab = 0;
		for(int i = 0; i < 4; i++)
			ten[ans[i]]++;
		for(int i = 0; i < n; i++){
			getline(cin, in);
			ss.str("");
			ss.clear();
			ss<<in;
			for(j = 0; j < 4; j++){
				cin>>temp[j];
				toten[temp[j]]++;
				if(temp[j] == ans[j])
					a++;
			}
			for(j = 0; j < 10; j++)
				if(ten[j])
					ab += min(ten[j], toten[j]);
			
			
			
			cout<<a<<"A"<<ab-a<<"B"<<endl;
		}
		
	}
	
	return 0;
}