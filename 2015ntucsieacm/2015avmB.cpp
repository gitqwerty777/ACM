#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define simulateNum 1000000

int T, N, M;
int randeck[1000];
int mixdeck[1000000];
double ans;

int main(){
  srand(time(NULL));
  while(scanf("%d %d", &M, &N) == 2){//num of card, num of deck
    int success = 0;
    for(int i = 0; i < simulateNum; i++){
      for(int j = 0; j < M; j++){
	for(int k = 0; k < N; k++){
	  mixdeck[j*M+k] = j;
	}
      }
      for(int j = 0; j < M; j++){
	int index = rand()%(M*N);
	while(mixdeck[index] == -1){
	  index = rand()%(M*N); 
	}
	randeck[j] = mixdeck[index];
	mixdeck[index] = -1;
      }
      int choose = randeck[rand()%M];
      int again = randeck[rand()%M];
      if(choose == again)
	success++;
    }
    printf("%lf\n", double(success)/simulateNum);
  }
  return 0;
}
