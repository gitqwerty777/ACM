#include <stdio.h>
#include <string.h>

int main(){
  int T;
  char s[5000005];
  int count[26];
  scanf("%d\n", &T);
  while(T--){
    gets(s);
    for(int i = 0;i < 26; i++)
      count[i] = 0;
    for(int i = 0, size = strlen(s); i < size; i++){
      int v = (s[i]-65+26-i%26)%26;
      count[v]++;
    }
    int maxv = count[0], maxi = 0;
    for(int i = 0;i < 26; i++)
      if(maxv < count[i]){
	maxv = count[i]; maxi = i;
      }
    printf("%d\n", maxv);
  }
}
