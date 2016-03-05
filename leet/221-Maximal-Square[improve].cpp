class Solution {
public:
  vector<vector<char>> matrix;
  int r, c;
  int maximalSquare(vector<vector<char>>& matrix) {
    this->matrix = matrix;
    r = matrix.size();
    if(r == 0)
      return 0;
    c = matrix[0].size();

    int nowSize = 1;
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++){
	updateSquare(i, j, nowSize);
      }
    return pow(max(0, nowSize-1), 2);
  }

  void updateSquare(int x, int y, int& nowSize){
    bool isFirst = true;
    while(1){
      if((x+nowSize-1 >= r) || (y+nowSize-1 >= c) ||( matrix[x][y] == '0'))
	return;
      if(isFirst){
	for(int i = x; i < x+nowSize; i++)
	  for(int j = y; j < y+nowSize; j++)
	    if(matrix[i][j] == '0')
	      return;
      } else {
	for(int i = x; i < x+nowSize; i++){
	if(matrix[i][y+nowSize-1] == '0')
	  return;
      }
      for(int i = y; i < y+nowSize; i++){
	if(matrix[x+nowSize-1][i] == '0')
	  return;
      } 
      }
      
      //all of square is 1
//printf("(%d, %d) size %d\n", x, y, nowSize);
      nowSize++;
    }
  }
};
