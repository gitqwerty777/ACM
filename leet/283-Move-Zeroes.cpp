class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int zeroNum = 0;
    for(int i = 0; i < nums.size(); i++){
      if(nums[i] == 0){
	zeroNum++;
	continue;
      } else {
	nums[i-zeroNum] = nums[i];
      }
    }

    for(int i = 0; i < zeroNum; i++){
      nums[nums.size()-1-i] = 0;
    }
  }
};
