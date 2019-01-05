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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first=head, *second=head, *third=head;
        for (int i=0;i<n;++i){
            first=first->next;
        }
        if (!first) return head->next;
        while (first->next){
            first=first->next;
            second=second->next;
        }
        second->next=second->next->next;
        return head;
    }
};