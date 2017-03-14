// equal should reduce to only one num...
class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(m == 0){
      nums1 = nums2;
      return;
    }
    if(n == 0){
      return;
    }
    int now1 = 0, now2 = 0;
    int rank = 0;
    vector<int> rank1, rank2;
    while(1){
      if(nums1[now1] > nums2[now2]){
	printf("push rank2 = %d\n", rank-1);
	rank2.push_back(rank++);
	
	now2++;
	if(now2 >= n)
	  break;
      } else {
	printf("push rank1 = %d\n", rank-1);
	rank1.push_back(rank++);
	
	now1++;
	if(now1 >= m)
	  break;
      }
    }
    while(now1 >= m && now2 < n){
      rank2.push_back(rank++);
      now2++;
    }
    while(now2 >= n && now1 < m){
      rank1.push_back(rank++);
      now1++;
    }
    for(int i = 0; i < m; i++)
      printf("%d, ", rank1[i]);
    puts("");
    for(int i = 0; i < n; i++)
      printf("%d, ", rank2[i]);
    puts("");
    vector<int> ans; now1 = 0; now2 = 0;
    for(int i = 0; i < m+n; i++){
      if(now1 < m && rank1[now1] == i){
	ans.push_back(nums1[now1++]);
      } else if(now2 < n && rank2[now2] == i){
	ans.push_back(nums2[now2++]);
      }
    }
    nums1 = ans;
  }
};
