/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* temp = head;
        while (temp) {
            Node* node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = node->next;
        }

        temp = head;
        while (temp) {
            Node* node = temp->next;
            if (temp->random) {
                node->random = temp->random->next;
            } else {
                node->random = nullptr;
            }
            temp = node->next; // Move to the next original node
        }

        Node* newHead = head->next;
        temp = head;
        while (temp) {
            Node* node = temp->next;
            temp->next = node->next; 
            
            if (node->next) {
                node->next = node->next->next;
            }
            
            temp = temp->next;
        }
        
        return newHead;
    }
};