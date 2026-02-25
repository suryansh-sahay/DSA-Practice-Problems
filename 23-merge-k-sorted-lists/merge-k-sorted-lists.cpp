/**3
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
    ListNode* func(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        for(auto arr:lists){
            if(arr)
            pq.push({arr->val, arr});
        }
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            temp->next=p.second;
            temp=temp->next;
            if(temp->next){
            pq.push({temp->next->val, temp->next});
            }
        }
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return func(lists);
    }  
};