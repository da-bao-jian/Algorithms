
//   Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

class Solution
{
public:
	int maxDepth(TreeNode *root)
	{
		return helper(root, 0);
	}
	int helper(TreeNode *root, int depth)
	{
		if (root == nullptr)
		{
			return depth;
		}
		depth += 1;
		return max(helper(root->left, depth), helper(root->right, depth));
	}
};