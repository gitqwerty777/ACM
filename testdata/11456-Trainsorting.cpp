#include <cstdio>
using namespace std;

int T, N;
int arr[2010];
int ans[2];
int maxnum;

//brute will failed by time limit exceed

void findLink(int d, int n){
  if(d == N){
    if(n > maxnum)
      maxnum = n;
  } else {
    if(n + N-d <= maxnum)
      return;
    //not choose
    findLink(d+1, n);
    //choose
    if(n == 0){
      ans[0] = ans[1] = arr[d];
      findLink(d+1, n+1);
    } else {
      if(ans[0] < arr[d]){
	int tmp = ans[0];
	ans[0] = arr[d];
	findLink(d+1, n+1);
	ans[0] = tmp;
      } else if(ans[1] > arr[d]){
	int tmp = ans[1];
	ans[1] = arr[d];
	findLink(d+1, n+1);
	ans[1] = tmp;
      }
    }
  }
}

void findMaxLink(){
  maxnum = 0;
  ans[0] = ans[1] = 0;
  findLink(0, 0);
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
