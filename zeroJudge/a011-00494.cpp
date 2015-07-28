#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int input;
	int count = 0;
	
	while((input = getchar()) != EOF){
		if(isalpha(input)){
			while((input = getchar()) != EOF){
				if(!isalpha(input))
					break;
			}
			count++;
			if(input == '\n'){
				printf("%d\n", count);
				count = 0;
			}
		} else if(input == '\n'){
			printf("%d\n", count);
			count = 0;
		}
	}

	return 0;
}