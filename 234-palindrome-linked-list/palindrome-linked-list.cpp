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
    ListNode* midNode(ListNode* slow){
        ListNode* fast=slow;
        while(fast && fast->next){
           fast=fast->next->next;
           slow=slow->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr) return true;
        ListNode* temp=midNode(head);
        ListNode* prev=nullptr;
        while(temp){
            ListNode* next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        while(head && prev){
            if(head->val != prev->val) return false;
            head=head->next;
            prev=prev->next;
        }
        return true;
    }
};