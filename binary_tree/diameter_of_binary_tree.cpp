// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.

 
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        helper(root, diameter);
        return diameter;
    }
    int helper(TreeNode* root, int &diameter){
        if(root == nullptr){
            return 0;
        }
        int leftPath = helper(root->left, diameter);
        int rightPath = helper(root->right, diameter);

        diameter = max(diameter, leftPath + rightPath);

        return max(leftPath , rightPath) +1;
    }
     
};