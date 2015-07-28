#include <iostream>
#include <cstdio>

using namespace std;

int arr[501][501];

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
	
	for(i = 0; i <= 500; i++){
			arr[0][i] = 0;
			arr[i][0] = 0;
		}
	
	while(1){
		n = Input();
		if(n == -1)
			break;
		m = Input();
		
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				arr[i][j] = Input();

		for(i = 2; i <= 2*n; i++){
			min = 1;
			while(i - min > n)
				min++;
			max = i < n+1 ? i : n+1;
			for(j = min; j < max; j++)
				arr[j][i-j] += arr[j-1][i-j] + arr[j][i-j-1] - arr[j-1][i-j-1];
		}
		
		int x, y, xx, yy, ans;
		for(i = 0; i < m; i++){
			x = Input();	y = Input();
			xx = Input();	yy = Input();
			
			ans = arr[xx][yy] - arr[x-1][yy] - arr[xx][y-1] + arr[x-1][y-1];
			printf("%d\n", ans);
		}
		
	}
	return 0;
}