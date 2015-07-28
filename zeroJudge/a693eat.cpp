#include <iostream>
#include <cstdio>

using namespace std;

int arr[100001];

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
	int n, m;
	int i, j, max, min;
	
	arr[0] = 0;
	
	while(1){
		n = Input();
		if(n == -1)
			break;
		m = Input();
		
		for(i = 1; i <= n; i++)
			arr[i] = Input() + arr[i-1];
			
		int x, y;
		for(i = 0; i < m; i++){
			x = Input();	y = Input();
			printf("%d\n", arr[y] - arr[x-1]);
		}
		
	}
	return 0;
}