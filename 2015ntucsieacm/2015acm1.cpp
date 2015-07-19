#include <stdio.h>
#include <string.h>

int main(){
  int T;
  char s[100];
  char a[100], b[100];
  char* c;
  char* d;
  int ai[2], bi[2];
  scanf("%d\n", &T);
  while(T--){
    gets(s);
    sscanf(s, "%s %s", a, b);
    sscanf(a, "%d%ii", &ai[0], &ai[1]);
    sscanf(b, "%d%ii", &bi[0], &bi[1]);
    printf("%d%+di\n", ai[0]+bi[0], ai[1]+bi[1]);
  }
}
