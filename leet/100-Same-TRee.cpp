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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if((p == NULL) || (q == NULL)){//if one is null, both should be null
      return (p == NULL) && (q == NULL);
    } else{
      if(p->val != q->val){//both are non null
	return false;
      } else {
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
      }
    } 
  }
};
