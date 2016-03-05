class ElementMap{
public:
  set<int> valueSet;
  map<int, int> valueToIndex;
  map<int, int> indexToValue;
  vector<int> count;
  void insert(int v){
    if(valueSet.insert(v).second == false){//exist
      count[valueToIndex[v]]++;
    } else {
      valueToIndex[v] = count.size();
      indexToValue[count.size()] = v;
      count.push_back(0);
    }
  }
  int getMajorElement(){
    int maxcount = 0, maxi = 0;
    for(int i = 0; i < count.size(); i++)
      if(count[i] > maxcount) {
	maxcount = count[i];
	maxi = i;
      }
    return indexToValue[maxi];
  }
};

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    /*map<int, int> count;
    for(int i = 0; i < nums.size(); i++){
      count[nums[rand()%nums.size()]]++;
    }
    */
    ElementMap m;
    for(int i = 0; i < nums.size(); i++){
      m.insert(nums[i]);
    }
    return m.getMajorElement();
  }
};
