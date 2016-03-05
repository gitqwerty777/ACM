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
  int minDepth(TreeNode* root) {
    if(root == NULL)
      return 0;
    root->val = 1;
    stack<TreeNode*> s;
    int mind = 2147483647;
    s.push(root);
    while(!s.empty()){
      TreeNode* t = s.top();
      s.pop();
      if(t == NULL){
	continue;
      }
      if(t->left){
	t->left->val = t->val + 1;
	s.push(t->left);
      }
      if(t->right){
	t->right->val = t->val + 1;
	s.push(t->right);
      }
      if(t->left == NULL && t->right == NULL){
	if(mind > t->val)
	  mind = t->val;
      }
    }
    return mind;
  }
};
