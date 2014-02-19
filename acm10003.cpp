#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int Input(){  
    char cha;  
    int x=0;  
    while(cha=getchar())  
        if((cha >= 48 && cha < 58) || cha == EOF) break;
	if(cha == EOF) return -1;
    x=cha-48;
    while(cha=getchar()) {  
        if(cha < 48 || cha >= 58) break;  
        x=x*10+cha-48;  
    }  
    return x;
}

int main(){
	int l, n, ansi, minsum;
	int cut[50];
	vector<int> cutl;
	
	l = Input();
	
	while(l){
		n = Input();
		cutl.clear();
		for(int i = 0; i < n; i++){
			cut[i] = Input();
			cutl.push_back(cut[i]);
		}
		
		
		/*
		ansi = 0;
		minsum = 2147483647;
		iterator::list<int> toCombine;
		for(int j = 0; j < n-1; j++){//°µn-1¦¸¦X¨Ö
			for(iterator::list<int> it = cutl.begin()+1; it != cutl.end(); it++){
				int sum = (*(it-1)) + (*it); 
				if(sum < minsum){
					minsum = sum;
					toCombine = it;
				}
			}
			ansi += minsum;
			*it = minsum;
			cutl.erase(it-1);
		}
		*/
		
		
		
		printf("The minimum cutting is %d.\n", ansi);
		string ans = "The minimum cutting is";
	
	}

	return 0;
}