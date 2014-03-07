#include <stdio.h>
#include <string.h>

int book[500];
int dp[500][501];//value = max books values by one scriber
	  //booknum, scribers
int main(){
	int N, C, B;//CUT BOOK
	scanf("%d", &N);
	while(N--){
		scanf("%d %d", &B, &C);
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < B; i++)
			scanf("%d", &book[i]);
		for(int i = 0; i < C; i++){
			
		}
		
	}
	return 0;
}