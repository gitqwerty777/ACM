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
  ListNode* reverseList(ListNode* head) {
    ListNode* nown = head;
    ListNode* pre = NULL;
    while(nown != NULL){
      ListNode* next = nown->next;
      nown->next = pre;
      pre = nown;
      nown = next;
    }
    return pre;
  }
};
