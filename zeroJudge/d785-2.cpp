#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

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

class node{
	public:
	int value = 0;
	int num = 0;
};

bool DFS(vector<node> stick,int &vertex, int nowver, int nowlo, int &sticklo){
	if(nowlo == sticklo){
		nowver++;
		nowlo = 0;
		if(nowver == vertex){
			if(stick.empty())
				return true;
			else
				return false;
		}
	}
	else if(stick.empty())
		return false;
	
	int plus, i, lo = stick.size(), count = 0;
	for(i = 0; i < lo; i++){
		if(nowlo + stick[i].value <= sticklo){
			//cout<<"plus"<<plus<<endl;
			vector<node> temp(stick);
			temp[i].num--;
			count++;
			if(temp[i].num == 0)
				temp.erase(temp.begin()+i);
				
			if(DFS(temp, vertex, nowver, nowlo + stick[i].value, sticklo))
				return true;
			else
				while(nowlo + stick[i].value*(count+1) <= sticklo){
					temp[i].num--;
					count++;
					if(temp[i].num == 0)
						temp.erase(temp.begin()+i);
						
					if(DFS(temp, vertex, nowver, nowlo + stick[i].value*count, sticklo))
						return true;
				}
		}
	}
	
	return false;
}

int comp(int a, int b){
	return a > b;
}

int main(){
	int n; string in; int vertex, stick_num;double sticklo;
	vector<int> stick;
	
	n = Input();

	while(n--){
		vertex = Input();
		stick_num = Input();
		
		stick.resize(stick_num);
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
		while(!stick.empty() && stick[0] == sticklo){
			vertex--;
			stick.erase(stick.begin());
		}
		
		vector<node> sticknode;
		sticknode.clear();
		i = 0;
		int count = 0;
		while(i < stick_num){
			sticknode.push_back(node(stick[i], 1));
			while(i +1 < stick_num && stick[i] == stick[i+1]){
				sticknode[count].num++; i++;}
			count++;
		}
		
		vector<int> compose;//列舉組合
		compose.clear();
		int max = stick[0];
		int min = stick[stick.size()-1];
		
		for(i = 0; i < )
		
		
		
		
		
		
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
		int stickloint = int(sticklo);
		if(vertex == 0 && stick.empty())
			puts("1");
		else if(DFS(sticknode, vertex, 0, 0, stickloint))
			puts("1");
		else
			puts("0");
	}

	return 0;
}
