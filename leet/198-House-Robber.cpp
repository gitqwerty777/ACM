class Solution {
public:
  int rob(vector<int>& nums) {
    if(nums.size() == 0)
      return 0;
    vector<int> sum;
    sum.resize(nums.size());
    if(nums.size()>=1)
      sum[0] = nums[0];
    if(nums.size()>=2)
      sum[1] = max(nums[0], nums[1]);
    for(int i = 2; i < nums.size(); i++){
      sum[i] = max(sum[i-2]+nums[i], sum[i-1]);
    }
    return sum[nums.size()-1];
  }
};
