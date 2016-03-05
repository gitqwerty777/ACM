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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* now1 = l1, *now2 = l2;
    ListNode* newHead = new ListNode(0);
    ListNode* nowNew = newHead;
    while(now1 != NULL && now2 != NULL){
      if(now1->val < now2->val){
	nowNew->next = now1;
	nowNew = nowNew->next;
	now1 = now1->next;
      } else {
	nowNew->next = now2;
	nowNew = nowNew->next;
	now2 = now2->next;
      }
    }
    if(now1 != NULL){
      nowNew->next = now1;
    } else if(now2 != NULL){
      nowNew->next = now2;
    }
    return newHead->next;
  }
};
