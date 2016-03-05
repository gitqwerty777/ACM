/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//sorted!
class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL)
      return head;
    int preVal = head->val-1;
    ListNode* nown = head;
    ListNode* newHead = new ListNode(0);
    ListNode* nowNew = newHead;
    while(nown != NULL){
      if(preVal != nown->val){
	nowNew->next = nown;
	nowNew = nowNew->next;
      }
      preVal = nown->val;
      nown = nown->next;
    }
    nowNew->next = NULL;
    return newHead->next;
  }
};
