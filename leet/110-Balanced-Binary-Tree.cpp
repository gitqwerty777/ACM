class NodeInformation{
public:
  int depth;
  bool isBalance;
};

class Solution {
public:
  NodeInformation getDepth(TreeNode* t){
    NodeInformation n;
    if(t == NULL){
      n.isBalance = true; n.depth = 0;
    } else if(t->left == NULL && t->right == NULL){
      n.isBalance = true; n.depth = 1;
    } else {
      NodeInformation ln = getDepth(t->left);
      NodeInformation rn = getDepth(t->right);
      n.isBalance = (abs(ln.depth-rn.depth) <= 1) && ln.isBalance && rn.isBalance;
      n.depth = max(ln.depth, rn.depth)+1;
    }
    return n;
  }
  
  bool isBalanced(TreeNode* root) {
    return getDepth(root).isBalance;
  }
};

