#include <stdio.h>
#include <stdlib.h>
#define MONTH 12
int sumofdays[MONTH] = {0,31,28,31,30,31,30,31,31,30,31,30};

struct t{
	int unit[5];//month day hour minute second
};

bool check_bigger(struct t &t1, struct t &t2){
	int i;
	for(i = 0; i < 5; i++){
		if(t1.unit[i] > t2.unit[i])
			return true;
		else if(t1.unit[i] == t2.unit[i])
			continue;
		else{
			return false;
		}
	}
	return false;
}

int get_day(struct t &T){
	return sumofdays[T.unit[0]-1] + T.unit[1];
}

int main(){
	int i;
	for(i = 1; i < MONTH; i++){
		sumofdays[i] += sumofdays[i-1];
	}
	
	int ary[] = {0,0,24,60,60};//進位單位
	
	int times;
	scanf("%d", &times);
	
	struct t t1, t2, diff;
	while(times--){
		scanf("%02d-%02d %02d:%02d:%02d,", &t1.unit[0], &t1.unit[1], &t1.unit[2], &t1.unit[3], &t1.unit[4]);
		scanf("%02d-%02d %02d:%02d:%02d", &t2.unit[0], &t2.unit[1], &t2.unit[2], &t2.unit[3], &t2.unit[4]);
		
		/*for(i = 0;i < 5; i++){
			printf("t1[%d] = %d, t2[%d] = %d\n", i, t1.unit[i], i, t2.unit[i]);
		}*/
		
		bool topast = check_bigger(t1, t2);
		if(topast){
			struct t temp;
			temp = t1;
			t1 = t2;
			t2 = temp;
		}
		
		diff.unit[1] = get_day(t2) - get_day(t1);
		//printf("diff days = %d\n", diff.unit[1]);
		for(i = 2; i < 5; i++){
			diff.unit[i] = t2.unit[i] - t1.unit[i];
		}
		for(i = 4; i > 1; i--){
			if(diff.unit[i] < 0){
				diff.unit[i-1]--;
				diff.unit[i] += ary[i];
			}
		}
		
		if(topast)	
			printf("-%d %02d:%02d:%02d\n", diff.unit[1], diff.unit[2], diff.unit[3], diff.unit[4]);
		else
			printf("%d %02d:%02d:%02d\n", diff.unit[1], diff.unit[2], diff.unit[3], diff.unit[4]);
	}
	return 0;
}