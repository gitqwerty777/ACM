//BASIC Character I V X L C D M Arabic numerals 1 5 10 50 100 500 1000

class Solution {
public:
  string roman;
  int* value;
  Solution(){
    roman = "IVXLCDM";
    value = (int*){1, 5, 10, 50, 100, 500, 1000};
  }
  int romanToInt(string s) {
    int v = 0;
    int preLevel = -10;
    for(int i = s.length()-1; i >= 0 ; i--){
      int level = roman.find(s[i]);
      if(level < preLevel){
	v -= value[level];
      } else {
	v += value[level];
      }
      preLevel = level;
    }
    return v;
  }
};
