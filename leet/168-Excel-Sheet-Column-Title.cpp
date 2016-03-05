class Solution {
public:
  string convertToTitle(int n) {
    vector<char> v;
    while(n > 0){
      v.push_back(((n-1)%26)+'A');
      n--;
      n /= 26;
    }
    reverse(v.begin(), v.end());
    string str(v.begin(), v.end());
    return str;
  }
};
