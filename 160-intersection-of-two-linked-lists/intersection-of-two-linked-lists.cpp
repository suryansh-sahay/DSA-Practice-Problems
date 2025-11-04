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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* n1=headA;
        ListNode* n2=headB;
        while(n1!=n2){
            if(!n1) n1=headB;
            else n1=n1->next;
            if(!n2) n2=headA;
            else n2=n2->next;
        }
        return n1;
    }
};