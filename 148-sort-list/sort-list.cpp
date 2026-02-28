/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMid(ListNode* head){
        ListNode* slow=head; ListNode* fast=head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* ms(ListNode* head){
        if(head==NULL || !head->next) return head;
        ListNode* mid=findMid(head);
        ListNode* l=head;
        ListNode* r=mid->next;
        mid->next=NULL;
       return merge(ms(l), ms(r));
    }
    ListNode* merge(ListNode* l, ListNode* r){
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(l&&r){
            if(l->val <= r->val) temp->next=l, l=l->next;
            else temp->next=r, r=r->next;
            temp=temp->next;
        }
        temp->next=(l)?l:r;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
    
       return ms(head);
    }
};