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
        if (head==NULL || head->next==NULL) return head;
        ListNode* current =head->next;
        ListNode* initial_head =head;
        while (current->next!=NULL){
            initial_head->next=current->next;
            current->next=head;
            head=current;
            current=initial_head->next;
        }
        initial_head->next=NULL;
        current->next=head;
        head=current;
        return head;
    }
};