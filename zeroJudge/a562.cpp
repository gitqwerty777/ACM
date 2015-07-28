#include <iostream>

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

class Coor{
	int x, y;
	
	Coor(int a, int b){
		x = a; y = b;
	}
};

class VCoor{
	vector<Coor> coor;
	
	VCoor(int a, int b){
		coor.push_back(Coor(a, b));
	}
};

int main(){
	bool iswalked[8][8];
	bool isnumwalked[101];
	vector<Coor> numwalk[101];
	vector<Coor> vnumwalk;
	int max;
	int arr[8][8];
	
	int m, n;
	int i, j;
	n = Input();
	
	while(n--){
		m = Input();
		//clear all
		memset(iswalked, false, sizeof(iswalked));
		memset(isnumwalked, false, sizeof(isnumwalked));
		for(i = 0; i < 101; i++)
			numwalk[i].clear();
		
		//input
		for(i = 0; i < m ; i++)
			for(j = 0; j < m; j++){
				arr[i][j] = Input();
				numwalk[arr[i][j]].push_back(Coor(i, j));
			}
		
		//walk
		//每個數字選一個出來
		for(i = 0; i < 101; i++)
			if(!numwalk[i].empty())
				max++;
			
		
		
		

	}

	return 0;
}