/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int maxDepth(TreeNode* root) {
    if(root == NULL)
      return 0;
    stack<TreeNode*> s;
    root->val = 1;
    s.push(root);
    int maxd = 1;
    while(!s.empty()){
      TreeNode* t = s.top();
      s.pop();
      if(t->val > maxd)
	maxd = t->val;
      if(t->left){
	t->left->val = t->val + 1;
	s.push(t->left);
      }
      if(t->right){
	t->right->val = t->val + 1;
	s.push(t->right);
      }
    }
    return maxd;
  }
};
