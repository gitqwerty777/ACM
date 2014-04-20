#include <stdio.h>
//reference:

unsigned int calculate_zero(long a){
	if(a < 0){
		return 0;
	}
	long oria = a;
	unsigned int nz = 0;
	unsigned int base = 10;
	
	nz += a % 10 + 1;//­Ó¦ì + {0}
	
	while(a >= base*10){
		if((a / base) % 10 == 0){
			nz += (a/(base*10) - 1) * base + (a % base + 1);
		} else {
			nz += (a/(base*10)) * base;
		}
		base *= 10;
	}
	//printf("from [0 to %ld] has %u zeros\n", oria, nz);
	return nz;
} 

int main(){
	long a, b;
	
	while(scanf("%ld %ld", &a, &b) == 2 && a != -1){
		unsigned int za = 0, zb = 0;
		za = calculate_zero(a-1);
		zb = calculate_zero(b);
		printf("%u\n", zb - za);
	}
	return 0;
}