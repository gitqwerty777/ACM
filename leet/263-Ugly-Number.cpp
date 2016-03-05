class Solution {
public:
  bool isUgly(int num) {
    if(num == 0)
      return false;
    int factor[3] = {2, 3, 5};
    for(int i = 0; i < 3; i++){
      while(num % factor[i] == 0){
	num /= factor[i];
      }
    }
    return num == 1;
  }
};
