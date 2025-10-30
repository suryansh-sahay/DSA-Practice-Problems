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
    bool hasCycle(ListNode *head) {
       const int cons=100000+1;
       while(head!=nullptr){
           head->val= cons;
           head=head->next;
           if(head!=nullptr && head->val==cons) return true;
       }
       return false;
    }
};