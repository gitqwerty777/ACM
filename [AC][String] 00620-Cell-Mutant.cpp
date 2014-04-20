#include <stdio.h>
#include <string.h>
char s[5000];
char ans[][12] = {"SIMPLE","FULLY-GROWN","MUTANT","MUTAGENIC"};

int main(){	
	int t,T;
	scanf("%d", &T);
	gets(s);
	for(int t = 0; t < T; t++){
		gets(s);
		int l = strlen(s);
		if(l == 1){
			puts(ans[0]);
		} else if(s[l-2] == 'A' && s[l-1] == 'B'){
			puts(ans[1]);
		} else if(s[0] == 'B' && s[l-1] == 'A'){
			puts(ans[2]);
		} else {
			puts(ans[3]);
		}
	}
	return 0;
}