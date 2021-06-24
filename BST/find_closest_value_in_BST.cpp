// write a function that takes a BST and a target integer value and returns the closest value to that target value
//contained in the BST *you can assume that there will only be one closest value in the BST
// Each BST node has an integer 'value', a 'left' child node, and a 'tight' child node. A node is said to
// be a valid BST node if and only if it satifies the BST property:
// 	its 'value' is strictly greater than the values of every node to its left; its 'value' is strictly less than or equal to
//	the values of every node to its right; and its children nodes are either valid BST nodes themselves or None/null

// tree = 	10
// 	      /    \
// 	     5     15
// 	    / \    / \
// 	   2   5  13  22
// 	  /         \
// 	 1          14
// 	target = 12
//	output = 13
#include <cmath>
class BST{
	public:
		int value;
		BST *left;
		BST *right;

		BST(int val);
		BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target, long closest=99999){
	if(abs(tree->value - target) < abs(closest - tree->value)){
		closest = tree->value;
	};
	if(target < tree->value && tree->left != nullptr){
		return findClosestValueInBst(tree->left, target, closest);
	} else if(target > tree->value && tree->right != nullptr){
		return findClosestValueInBst(tree->right, target, closest);
	} else {
		return closest;
	};
};