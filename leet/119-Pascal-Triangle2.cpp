class Solution {
 public:
  vector<vector<int>> v;
  int nowMaxRow;
  Solution(){
    nowMaxRow = 2;
    v.resize(nowMaxRow);
    for(int i = 0; i < nowMaxRow; i++){
      v[i].resize(i+1);
    }

    v[0][0] = 1;
    v[1][0] = 1;                                              v[1][1] = 1;
  }
  vector<int> getRow(int rowIndex) {
    if(rowIndex < nowMaxRow){
      return v[rowIndex];
    }
    v.resize(rowIndex+1);
    for(int i = nowMaxRow; i <= rowIndex; i++){
      v[i].resize(i+1);
    }
    for(int i = nowMaxRow; i <= rowIndex; i++){
      for(int j = 0; j < i+1; j++){
	if(j == 0 || j == i){
	  v[i][j] = 1;
        } else {
          v[i][j] = v[i-1][j-1] + v[i-1][j];
        }
      }
    }
    nowMaxRow = rowIndex;
    return v[rowIndex];
  }
};
