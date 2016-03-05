class TreeNodeWithDepth{
public:
  TreeNodeWithDepth(TreeNode* t, int d){
    this->t = t;
    this->depth = d;
  }
  TreeNode* t;
  int depth;
};

class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    stack<TreeNodeWithDepth*> s;
    vector<vector<int> > v;
    TreeNodeWithDepth* rootT = new TreeNodeWithDepth(root, 0);
    s.push(rootT);
    while(!s.empty()){
      TreeNodeWithDepth* t = s.top();
      s.pop();
      if(t->t == NULL)
	continue;
      if(v.size() < t->depth+1)
	v.resize(t->depth+1);
      v[t->depth].push_back(t->t->val);
      s.push(new TreeNodeWithDepth(t->t->left, t->depth+1));
      s.push(new TreeNodeWithDepth(t->t->right, t->depth+1));
    }
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
      reverse(v[i].begin(), v[i].end());
    }
    return v;
  }
};
