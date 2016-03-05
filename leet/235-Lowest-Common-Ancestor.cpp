#include <string>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* root;
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    this->root = root;
    int v[2];
    v[0] = p->val;
    v[1] = q->val;
    vector<TreeNode*> pv = findAncestors(v[0]);
    vector<TreeNode*> qv = findAncestors(v[1]);
    int minDepth = max(0, int(min(pv.size(), qv.size()))-1);
    for(int i = minDepth; i >= 0; i--){
      if(pv[i]->val == qv[i]->val)
	return pv[i];
    }
  }

  std::vector<TreeNode*> findAncestors(int v){
    stack< vector<TreeNode*> > s;
    vector<TreeNode*> initv;
    initv.push_back(root);
    s.push(initv);
    while(!s.empty()){
      vector<TreeNode*> tv = s.top();
      s.pop();
      TreeNode* t = tv[tv.size()-1];
      if(t == NULL)
	continue;
      if(t->val == v){
	printf("find ancestor\n");
	for(int i = 0; i < tv.size(); i++){
	  printf("%d, ", tv[i]->val);
	}
	puts("");
	return tv;
      }
      vector<TreeNode*> newv;
      if(t->left != NULL){
	newv = tv;
	newv.push_back(t->left);
	s.push(newv);
      }
      if(t->right != NULL){
	newv = tv;
	newv.push_back(t->right);
	s.push(newv);
      }
    }
  }
};

int main(){
  Solution s;
  TreeNode* root = new TreeNode(5);
  TreeNode* p = new TreeNode(3);
  TreeNode* p1 = new TreeNode(2);
  TreeNode* p2 = new TreeNode(4);
  p->left = p1; p->right = p2;
  TreeNode* p11 = new TreeNode(1);
  p1->left = p11;
  TreeNode* q = new TreeNode(6);
  root->left = p;
  root->right = q;
  TreeNode* t = s.lowestCommonAncestor(root, p11, p2);
  printf("ancestor = %d\n", t->val);
}
