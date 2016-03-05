class Solution {
public:
  int map[100];
  Solution(){
    map[10] = 1;
    map[11] = 2;
    map[12] = 3;
    map[13] = 4;
    map[14] = 5;
    map[15] = 6;
    map[16] = 7;
    map[17] = 8;
    map[18] = 9;
  }
  int addDigits(int num) {
    int sum = 0;
    while(num > 0){
      sum += num%10;
      if(sum >= 10)
	sum = map[sum];
      num /= 10;
    }
    return sum;
  }
};
