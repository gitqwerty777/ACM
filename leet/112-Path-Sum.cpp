class TreeNodeWithDepth{
public:
  TreeNodeWithDepth(TreeNode* t, int d){
    this->t = t;
    this->sum = d;
  }
  TreeNode* t;
  int sum;
};

class Solution {
public:
  bool hasPathSum(TreeNode* root, int sum) {
    if(root == NULL)
      return false;
    stack<TreeNodeWithDepth*> s;
    TreeNodeWithDepth* t = new TreeNodeWithDepth(root, 0);
    s.push(t);
    while(!s.empty()){
      TreeNodeWithDepth* t = s.top();
      s.pop();
      if(t->t == NULL){
	
	continue;
      }
      if(t->t->left == NULL && t->t->right == NULL){
        if(t->sum+t->t->val == sum){
	  return true;
	}
	continue;
      }
      s.push(new TreeNodeWithDepth(t->t->left, t->sum+t->t->val));
      s.push(new TreeNodeWithDepth(t->t->right, t->sum+t->t->val));
    }
    return false;
  }
};
