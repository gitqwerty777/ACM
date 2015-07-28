#include <iostream>
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
	int n;
	int i;
	int arr[200];
	vector<int> pair[2];
	
	while(1){
		n = Input();
		for(i = 0; i < n; i++)
			arr[i] = Input();
	}

	return 0;
}