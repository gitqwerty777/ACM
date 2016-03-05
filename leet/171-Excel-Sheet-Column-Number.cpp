class Solution {
public:
  int titleToNumber(string s) {
    int num = 0;
    int base = 1;
    for(int i = s.length()-1; i >= 0; i--){
      num += (s[i]-'A'+1)*base;
      base *= 26;
    }
    return num;
  }
};
