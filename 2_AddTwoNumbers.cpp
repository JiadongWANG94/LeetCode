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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode tmp_node=ListNode((l1->val+l2->val)%10);
        // NOT WORKING: ListNode *ans_tmp=&tmp_node;
        ListNode *ans_tmp=new ListNode((l1->val+l2->val)%10);
        ListNode *ans=ans_tmp;
        int tmp=(l1->val+l2->val)/10;
        while (l1->next!=NULL || l2->next!=NULL){
            int v=tmp;
            if (!(l1->next==NULL)){
                l1=l1->next;
                v+=l1->val;
            }
            if (!(l2->next==NULL)){
                l2=l2->next;
                v+=l2->val;
            }
            tmp=v/10;
            ans_tmp->next=new ListNode(v%10);
            ans_tmp=ans_tmp->next;
        }
        if (tmp!=0){
            ans_tmp->next=new ListNode(tmp);
        }
        return ans;
    }
}; 