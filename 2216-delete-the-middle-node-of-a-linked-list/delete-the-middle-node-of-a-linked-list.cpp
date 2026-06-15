
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || head -> next == NULL)return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast -> next != NULL){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
          ListNode* deletenode = prev -> next ;
          prev -> next = slow -> next;
           delete(deletenode);
           return head;
    }
};