#include <stdio.h>

long double C(int x, int y){
  long double re = 1;
  for(int i = 1; i <= y; i++){
      re *= x-i+1;
      re /= i;
  }
  return re;
}

int N, M;
long double Ans = 0;

int main()
{
  while(scanf("%d %d", &N, &M) == 2){
    for(int i =1, n = (N<M)?N:M; i <= n; i++)
      Ans += C(M, i)*C(M*N-M, N-i)*i*i;
    Ans /= N*C(M*N, N);
    printf("%.9lf\n", double(Ans));
  }
}
