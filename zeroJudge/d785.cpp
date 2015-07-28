#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>

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

int vertex, stick_num; double sticklo;int stickloint;vector<int> stick(31); bool isuse[31];

bool DFS(bool *isuse ,int nowindex, int nowver, int nowlo){
	if(nowver == vertex-1)
		return true;
	
	int plus, i;
	for(i = nowindex; i < stick_num; i++){
		if(!isuse[i] && nowlo + stick[i] <= stickloint){
			//cout<<"plus"<<plus<<endl;
			isuse[i] = true;
			bool ok = false;
			if(nowlo + stick[i] == stickloint)
				ok = DFS(temp, nowver+1, nowver+1, 0);//nowver op
			else
				ok = DFS(temp, i+1, nowver, nowlo+stick[i]);
			
			if(ok)
				return true;
			else
				isuse[i] = false;
		}
	}
	//找不到組合
	return false;
}

int comp(int a, int b){
	return a > b;
}

int main(){
	int n;

	n = Input();

	while(n--){
		vertex = Input();
		stick_num = Input();
		
		int sum = 0;
		for(int i = 0; i < stick_num; i++){
			stick[i] = Input();
			sum += stick[i];
		}
		
		sticklo = double(sum) / double(vertex);
		if(int(sticklo) != sticklo){
			puts("0");
			continue;
		}
		
		sort(stick.begin(), stick.end(), comp);
		if(sticklo < stick[0]){
			puts("0");
			continue;
		}
		/*
		int max = 100, min = 1;
		while(stick[max] == 0)
			max--;
		while(stick[min] == 0)
			min++;
		if(sticklo < max){
			cout<<"0"<<endl;
			continue;
		}
		
		
		int bu;
		if(sticklo >= 100)
			bu = sticklo - 100;
		else
			bu = 0;
		for(int i = bu; i < 101; i++){//ok?不影響？
			if(stick[sticklo - i] && stick[i])
				while(stick[sticklo - i] && stick[i]){
					stick[sticklo - i] --;
					stick[i]--;
					vertex--;
				}
		}
		*/
		stickloint = int(sticklo);
		memset(isuse, false, sizeof(bool)*31);
		if(DFS(isuse , 0 , 0, 0))
			puts("1");
		else
			puts("0");
	}

	return 0;
}
