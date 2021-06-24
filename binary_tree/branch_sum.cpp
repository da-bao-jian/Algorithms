// Write a function that takes in a binary tree and returns a list of its branch sums ordered from 
// leftmost branch sum to rightmost branch sum.
// a branch sum is the sum of all values in a binary tree branch. A binary tree branch is a path of nodes in a tree that starts at the root
// node and ends at any leaf node. 
// Each binary tree node has an integer value, a left child node, and a right child node. 
// Children nodes can either be bginary tree nodes themselves or None/null
// tree = 	1
// 	      /   \
// 	     2     3
// 	    / \   / \
// 	   4   5 6   7
// 	  / \   \
// 	 8   9  10
// 	output = [15, 16, 18, 10, 11]
// 	15 = 1 + 2 + 3 + 4 + 8
//	16 = 1 + 2 + 3 + 4 + 9 
//  	18 = 1 + 2 + 5 + 10 ...

#include <vector>
using namespace std;
class BinaryTree{
	public:
		int value;
		BinaryTree *left;
		BinaryTree *right;
		BinaryTree(int value){
			this->value = value;
			left = nullptr;
			right = nullptr;
		};
};
// first, dfs the tree 

void gatherSums(BinaryTree*root, int sum, vector<int> &res){
	if(root == nullptr){ return; }
	sum += root->value;
	if(root-> left == nullptr && root->right == nullptr){
		res.push_back(sum);
		return;
	};
	gatherSums(root->left, sum, res);
	gatherSums(root->right, sum, res);
};

vector<int> branchSum(BinaryTree *root){
	vector<int> res;
	int sum = 0;
	gatherSums(root, sum, res);
	return res;
}
