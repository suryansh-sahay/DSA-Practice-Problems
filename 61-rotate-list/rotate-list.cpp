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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || head->next==NULL) return head;
        if(k==0) return head;
        int size=0;
        ListNode* check=head;
        while(check) size++, check=check->next;
        k%=size;
        if(k==0) return head;
        ListNode* temp=head;
        while(size-k-1) temp=temp->next,size--;
        ListNode* ans=temp->next;
        temp->next=NULL;
        temp=ans;
        while(temp->next) temp=temp->next;
        temp->next=head;
        return ans;
    }
};