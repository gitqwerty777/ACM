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
  void deleteNode(ListNode* node) {
    ListNode* nextNode = node->next;//not NULL by problem description
    ListNode* nextNode2 = nextNode->next;
    node->val = nextNode->val;
    node->next = nextNode2;
  }
};
