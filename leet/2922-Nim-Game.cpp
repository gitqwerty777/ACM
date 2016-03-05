class Solution {
public:
  bool canWinNim(int n) {
    //0 lose
    //1~3 win
    //4 lose
    //5~7 win
    //8 lose
    if(n % 4 == 0)
      return false;
    else
      return true;
  }
};


