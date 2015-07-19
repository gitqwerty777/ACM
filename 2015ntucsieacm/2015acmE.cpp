#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T, N;
int input[50];
double ans;

int cmp(const void* av, const void *bv){
  return (*(int*)av) > (*(int*)bv);
}

void greedy(){
  ans = 0;
  qsort(input, N, sizeof(int), cmp);
  ans = double(input[0] + input[1])/2;
  for(int i = 2; i < N; i++){
    ans = (ans+input[i])/2;
  }
}

int main(){
  scanf("%d", &T);
  while(T--){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
      scanf("%d", &input[i]);
    }
    greedy();
    printf("%lf\n", ans);
  }
  return 0;
}
