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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* temp=head;
        while(temp) count++, temp=temp->next;
        
        if(count-n==0) {head=head->next; return head;}

        ListNode* temp2=head;
        while(count-n>1 && temp2){
           temp2=temp2->next;
           count--;
        }
        if(temp2) temp2->next=temp2->next->next;
        return head;
    }
};