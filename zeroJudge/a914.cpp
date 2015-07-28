#include <stdio.h>
#include <vector>
/*
class number{
	public:
		vector<int> n;
		class number add(class number);
};
typedef class number num;
*/
int main(){
	//num[100000];
	long long num[41];
	num[0] = 0;
	num[1] = 1;
	num[2] = 1;
	for(int i = 3; i < 41; i++){
		num[i] = num[i-1] + num[i-2];
	}
	int T, N;
	scanf("%d", &T);
	
	for(int t = 0; t < T; t++){
		scanf("%d", &N);
		printf("%lld\n", num[N]);
	}
	return 0;
}



