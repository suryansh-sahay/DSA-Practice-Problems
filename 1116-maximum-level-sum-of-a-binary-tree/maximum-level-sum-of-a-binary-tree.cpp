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
    int maxLevelSum(TreeNode* root) {
        int level = 1 ;
        int levelModified = 0; 
        int levelSum = INT_MIN ;
        queue<TreeNode*> q ;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            levelModified++ ; 
            int sum = 0  ; 
            while(size--){
                TreeNode* frontNode = q.front();
                sum = sum + frontNode->val;
                q.pop();

                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            if(sum>levelSum){
                levelSum = sum ; 
                level = levelModified ; 
            }
        }
        return level ; 
        
    }
};