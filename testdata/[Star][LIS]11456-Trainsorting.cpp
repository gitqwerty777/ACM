#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T, N;
int arr[2010];
int maxnum;
int lis[2010];
int lds[2010];

void LISLDS(){
  for(int i = 0; i < N; i++){
    lis[i] = 1;
    lds[i] = 1;
  }

  //lis[i] = lis start from i ~ N
  for(int i = N-1; i >= 0; i--)
    for(int j = N-1; j > i; j--)
      if(arr[j] < arr[i])
	lds[i] = max(lds[i], lds[j]+1);
      else
	lis[i] = max(lis[i], lis[j]+1);
}

void findMaxLink(){
  LISLDS();
  maxnum = 0;
  for(int i = 0; i < N; i++)
    maxnum = max(maxnum, lis[i]+lds[i]-1); // if max at index i, means the first part of train is i
}

int main(){
  scanf("%d", &T);
  while(T--){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
      scanf("%d", &arr[i]);
    findMaxLink();
    printf("%d\n", maxnum);
  }
}
