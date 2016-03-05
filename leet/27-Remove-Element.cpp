class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    vector<int> arr;
    arr.clear();
    int len = nums.size();
    for(int i = 0; i < nums.size(); i++){
      if(nums[i] == val){
	len--;
      } else {
	arr.push_back(nums[i]);
      }
    }
    nums = arr;
    return len;
  }
};
