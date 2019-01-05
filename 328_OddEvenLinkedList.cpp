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
        if (!head || !head->next) return head;
        ListNode *odd_head=head, *even_head=head->next;
        ListNode *odd_Tail=odd_head, *even_Tail=even_head;
        ListNode *tail=even_Tail->next;
        while (tail!=NULL){
            if (tail==even_Tail->next){
                odd_Tail->next = tail;
                odd_Tail = odd_Tail->next;
            }
            else{
                even_Tail->next=tail;
                even_Tail=even_Tail->next;
            }
            tail=tail->next;
        }
        even_Tail->next = NULL;
        odd_Tail->next = even_head; 
        return odd_head;
    }
};

