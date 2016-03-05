class Solution {
public:
  bool isAnagram(string s, string t) {
    int count[2][26];
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 26; j++)
	count[i][j] = 0;
    if(s.length() != t.length())
      return false;
    for(int i = 0; i < s.length(); i++){
      count[0][s[i]-'a']++;
    }
    for(int i = 0; i < t.length(); i++){
      count[1][t[i]-'a']++;
    }
    for(int i = 0; i < 26; i++){
      if(count[0][i] != count[1][i])
	return false;
    }
    return true;
  }
};

