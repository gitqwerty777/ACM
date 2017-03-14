class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    //only 9x9 envolved
    vector<set<int> > square;
    vector<set<int> > row;
    vector<set<int> > col;
    square.resize(9);
    row.resize(9);
    col.resize(9);
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
	if(board[i][j] != '.'){
	  int val = board[i][j] - '0';
	  int squareIndex = (i / 3) + (j / 3) * 3;
	  if(square[squareIndex].insert(val).second && row[i].insert(val).second && col[j].insert(val).second){
	    continue;
	  } else {
	    return false;
	  }
	}
      }
    }
    return true;
  }
};
