class Solution {
public:
    int sum = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        return helper(root, low, high);
    }
    int helper(TreeNode* root, int low, int high){
        if(root->left && root->val >= low){
            helper(root->left, low, high); 
        }
        if(root->val >= low && root->val <= high){
            sum += root->val;
        }
        if(root->right && root->val <= high){
            helper(root->right, low, high);
        }
        return sum;
    }
};