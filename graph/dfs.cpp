//You are giben a Node class that has a name and an array of optional children nodes.
// When put together, nodes form an acyclic tree like structure
// implement the depthFirstSearch method on the Node class, which takes in an empty array, traverse the tree
// using the Depth-first search approach (specifically navigating the tree from left to right), stores all of the nodes'
// names in the input array, and returns it.
// graph =        A
//		/ | \
//	       B  C  D
//	      / \   / \
//	     E  F  G   H
//	       / \  \
//	      I   J  K 
//   	output = [A,B,E,F,I,J,C,D,G,K,H]

#include <vector>
#include <string>
using namespace std;
class Node{
	public:
		string name;
		vector <Node*> children;

		Node(string str){name = str;}

		Node *addChild(string name){
			Node *child = new Node(name);
			children.push_back(child);
			return this;
		};

		vector<string> depthFirstSearch(vector<string> *array){
			array->push_back(name);
			if(children.size() == 0){
				return {};
			} 
			for(Node *child: children){
				child->depthFirstSearch(array);
			};

			return *array;
		};

}