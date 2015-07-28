#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void *b){
	return *(long long*)a < *(long long *)b;
}

void swap(long long &a, long long &b){
	long long temp = a;
	a = b;
	b = temp;
	return;
}

long long gcd(long long a, long long b){
	if(a < b){
		swap(a, b);
	}
	while(b != 0){
		a %= b;
		if(a < b){
			swap(a, b);
		}
	}
	return a;
}

int main(){
	int i, j;
	int test_num, duck_num;
	long long duck[10000];
	
	scanf("%d", &test_num);
	
	for(i = 0; i < test_num; i++){
		scanf("%d", &duck_num);
		for(j = 0; j < duck_num; j++){
			scanf("%lld", &duck[j]);
		}
		qsort(duck, duck_num, sizeof(long long), cmp);
		for(j = 0; j < duck_num-1; j++){
			duck[j] -= duck[j+1];
		}
		long long ans = duck[0];
		for(j = duck_num-2; j > 0; j--){
			ans = gcd(ans, duck[j]);
		}
		printf("%lld\n", ans);
	}

	return 0;
}