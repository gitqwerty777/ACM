#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (a > b)?a:b

int gcd(int a, int b)
{
    while (a && b)
    {
		if(a < b)
			b %= a;
		else
			a %= b;
    }
    return max(a, b);
}

int main(){
	int test_num;
	int num;
	int koyu[10000];//¥i³½ªG
	int i, j;
	
	scanf("%d", &test_num);
	
	while(test_num-- > 0){
		scanf("%d", &num);
		for(i = 0; i < num; i++){
			scanf("%d", &koyu[i]);	
		}
		//qsort(koyu, num, sizeof(int), cmp);
		
		if(koyu[num-1] <= 1 || num == 1){
			printf("%d\n", koyu[num-1]);
			continue;
		}
		
		int nowans = gcd(koyu[1], koyu[0]);
		int tempans;
		for(i = 2; i < num; i++){
			//if(koyu[i] % nowans == 0)
			//	continue;
			//tempans = gcd(koyu[0], koyu[i]);
			nowans = gcd(koyu[i], nowans);
		}
		
		printf("%d\n", nowans);
	}


	return 0;
}