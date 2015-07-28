#include <stdio.h>
#include <string.h>

int main(){
	char qnum[20] = "";
	char ans[400] = "";
	bool even, testeven;
	
	
	while(gets(ans)){
		if(strcmp(ans, "0") == 0){
			break;
		}
		
		if((ans[strlen(ans)-1] - '0') % 2 == 0){//°¸
			even = true;
		} else {
			even = false;
		}
		
		testeven = true;//0
		while(gets(qnum) && strcmp(qnum, "0") != 0){
			if((qnum[strlen(qnum)-1] - '0') % 2 != 0){
				testeven = !testeven;
			}
		}
	
		if(testeven == true && even == false || testeven == false && even == true){//is this ok?
			puts("0");
		} else if(even == true){
			puts("1");
		} else {
			puts("2");
		}
		
		//memset(ans, '\0', 400);
	}
	return 0;
}