class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0)
      return 0;
    vector<int> newarr;
    newarr.clear();
    int pre = (nums[0] == 0)?1:0;
    int len = nums.size();
    for(int i = 0; i < nums.size(); i++){
      if(pre == nums[i]){
	len--;
      } else {
	newarr.push_back(nums[i]);
	pre = nums[i];
      }
    }
    nums = newarr;
    return len;
  }
};
