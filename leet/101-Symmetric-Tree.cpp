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
  bool isSymmetric(TreeNode* root) {
    if(root == NULL)
      return true;
    return checkSymmetry(root->left, root->right);
  }

  bool checkSymmetry(TreeNode* l, TreeNode* r){
    if(l == NULL && r == NULL)
      return true;
    else if(l == NULL || r == NULL || l->val != r->val)
      return false;
    else
      return checkSymmetry(l->right, r->left) && checkSymmetry(l->left, r->right);
  }
};
