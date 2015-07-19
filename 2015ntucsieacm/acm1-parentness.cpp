#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T;
char s[104];
int stack[2];

int main(){
  scanf("%d\n", &T);
  while(T--){
    gets(s);
    stack[0] = 0; stack[1] = 0;
    int size = strlen(s);
    for(int i = 0; i < size; i++){
      if(s[i] == '('){
	stack[0]++;
      } else{
	if(stack[0] > 0){
	  stack[0]--;
	} else {
	  stack[1]++;
	}
      }
    }
    printf("%d\n", stack[0]+stack[1]);
  }
  return 0;
}
