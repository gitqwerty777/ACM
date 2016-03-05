/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* nowa = headA;
    set<ListNode*> nodeset;
    while(nowa != NULL){
      nodeset.insert(nowa);
      nowa = nowa->next;
    }
    ListNode* nowb = headB;
    while(nowb != NULL){
      if(nodeset.insert(nowb).second == false){
	return nowb;
      }
      nowb = nowb->next;
    }
    return NULL;
  }
};
