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
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* kthnode(ListNode* head, int k){
        while(head&&k>1){
            head=head->next;
            k--;
        }
        return head;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=head;
        while(temp){
            ListNode* kth=kthnode(temp, k);
            if(!kth){
                if(prev) prev->next=temp;
                break;
            }
            ListNode* next = kth->next;
            kth->next=NULL;
            if(temp==head) head=kth;
            else prev->next=kth, prev=temp;
       
            reverse(prev);  
            temp=next;
        }
        return head;
    }
};