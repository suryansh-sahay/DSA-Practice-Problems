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
    ListNode* reverseList(ListNode* head) {
        ListNode* tail=nullptr;
        ListNode* temp=nullptr;
        while(head!=nullptr){
            temp=head;
            head=head->next;
            temp->next=tail;
            tail=temp;
        }
        return temp;
    }
};