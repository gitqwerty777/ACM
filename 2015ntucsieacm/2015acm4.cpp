#include <stdio.h>
#include <stdlib.h>

int main(){
  int T, N;
  scanf("%d", &T);
  int path[100001][3];
  
  while(T--){
    scanf("%d", &N);
    int* d = (int *)malloc(sizeof(int)*N*sizeof(int)*N);
    for(int i = 0; i < N-1; i++)
      scanf("%d%d%d", &path[i][0], &path[i][1], &path[i][2]);
    
  }
}
