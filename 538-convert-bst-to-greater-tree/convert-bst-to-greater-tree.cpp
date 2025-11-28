class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        TreeNode* cur = root;
        while (cur) {
            if (cur->right) {
                TreeNode* suc = cur->right;
                while (suc->left && suc->left != cur)
                    suc = suc->left;
                if (!suc->left) {
                    suc->left = cur;
                    cur = cur->right;
                } else {
                    // add greater sum
                    int temp = cur->val;
                    cur->val += sum;
                    sum += temp;

                    suc->left = nullptr;
                    cur = cur->left;
                }
            } else {
                // add greater sum
                int temp = cur->val;
                cur->val += sum;
                sum += temp;

                cur = cur->left;                
            }
        }
        return root;
    }
};