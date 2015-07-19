#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

vector< vector<int> > ans;

int getBase(int n, int b){
  int sum = 0;
  sum += n % b;
  n /= b;
  while(n >= b){
    sum += n%b;
    n /= b;
  }
  return (sum+n);
}

int main(){
  int T, N;
  scanf("%d", &T);
  ans.resize(1001);
  
  while(T--){
    scanf("%d", &N);
    if(ans[N].size() == 0){
      for(int i = 2; i < N; i++)
	ans[N].push_back(getBase(N, i));
    }
    for(int i = 0; i < ans[N].size(); i++){
      if(i == 0)
	printf("%d", ans[N][i]);
      else
	printf(" %d", ans[N][i]);
    }
    printf("\n");
  }
}
