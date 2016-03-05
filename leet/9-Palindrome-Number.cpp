class Solution {
public:
  bool isPalindrome(int x) {
    if(x < 0)
      return false;
    char* s = new char[100];
    sprintf(s, "%d", x);
    printf("string = %s\n", s);
    int len = strlen(s);
    for(int i = 0; i < len; i++){
      if(s[i] != s[len-1-i])
	return false;
    }
    return true;
  }
};
