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
    ListNode* removeElements(ListNode* head, int val) {
        if (head==NULL) return NULL;
        ListNode* first=head;
        while (first!=NULL && first->next !=NULL && first->val==val){
            first=first->next;
        }
        if (first->val ==val) return NULL;
        if (first->next==NULL) return first;
        ListNode* second =first, *result = first;
        first=first->next;
        while(first!=NULL){
            while(first->val==val && first->next!=NULL) first=first->next;
            if (first->val ==val) {
                second->next=NULL;
                break;
            }
            else{
                second->next=first;
                second=second->next;
                first=first->next;
            }
        }
        return result;
    }
};