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
  ListNode* oddEvenList(ListNode* head) {
    ListNode* nown = head;
    ListNode* oddHead = new ListNode(0);
    ListNode* nowOdd = oddHead;
    ListNode* evenHead = new ListNode(0);
    ListNode* nowEven = evenHead;
    int count = 1;
    while(nown != NULL){
      if(count % 2 == 1){
	nowOdd->next = nown;
	nowOdd = nowOdd->next;
      } else {
	nowEven->next = nown;
	nowEven = nowEven->next;
      }
      count++;
      nown = nown->next;
    }
    nowOdd->next = evenHead->next;
    nowEven->next = NULL;
    return oddHead->next;
  }
};
