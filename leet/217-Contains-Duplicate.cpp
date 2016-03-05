class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    vector< set<int> > hashtable;
    hashtable.resize(65536);
    for(int i = 0; i < nums.size(); i++)
      if(hashtable[((nums[i]>0)?nums[i]:-nums[i]) % 65536].insert(nums[i]).second == false){
	return true;
      }
    return false;
  }
};
