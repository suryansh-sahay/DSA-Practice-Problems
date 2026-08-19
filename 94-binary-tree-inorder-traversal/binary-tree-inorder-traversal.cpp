/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*>st;
        TreeNode* node = root;
        vector<int>ans;

        while(!st.empty() || node != nullptr){
            while(node != nullptr){
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            node = node->right;
        }
    return ans;
    }
};