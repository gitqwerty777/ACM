#include <stdio.h>

inline void print_NOT(int ai, int bi){
	printf("(A%d|B%d)|(A%d|B%d)", ai, bi, ai, bi);
}

void print_Cout(int n){
	if(n == 0){
		print_NOT(0, 0);
	}
	printf("((A%d|B%d)|(", n, n);
	print_Cout(n-1);
	printf("|((A%d|A%d)|(B%d|B%d))))", n, n, n, n);
}

int main(){
	int N, in;
	scanf("%d", &N);
	
	while(scanf("%d", &in) != EOF){
		for(int i = in-1; i >= 0; i--){
			print_Cout(in-1);
		}
	}
	return 0;
}