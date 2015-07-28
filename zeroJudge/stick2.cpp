#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

bool DFS(vector<int> stick,int vertex, int nowver, int nowlo, int sticklo){
	vector<int> temp = stick;
	if(nowlo == sticklo){
		nowver++;
		nowlo = 0;
	}
	
	for(int i = 0; i < stick.size(); i++){
		if(nowlo + stick[i] <= sticklo){
			temp.erase(temp.begin()+i);
			if(DFS(temp, vertex, nowver, nowlo + stick[i], sticklo))
				return true;
		}
	}
	
	return false;
}

int comp(int a, int b){
	return a > b;
}
int main(){
	int n; string in; int vertex, stick_num; stringstream ss; double sticklo;
	vector<int> stick;
	
	cin>>n;
	getline(cin, in);//dumb
	
	while(n--){
		getline(cin, in);
		ss.str("");		ss.clear();		ss<<in;
		ss>>vertex>>stick_num;
		
		stick.resize(stick_num);
		int sum = 0; int input;
		for(int i = 0; i < stick_num; i++){
			ss>>stick[i];
			
			sum += stick[i];
		}
		
		sticklo = double(sum) / double(vertex);
		if(int(sticklo) != sticklo){
			cout<<"0"<<endl;
			continue;
		}
		
		sort(stick.begin(), stick.end(), comp);
		if(sticklo < stick[0]){
			cout<<"0"<<endl;
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
		if(DFS(stick, vertex, 0, 0, sticklo))
			cout<<"1"<<endl;
		else
			cout<<"0"<<endl;
	}

	return 0;
}