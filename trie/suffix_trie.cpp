#include <unordered_map>
using namespace std;

class TrieNode{
	public:
		unordered_map<char, TrieNode *> children;
};

class SuffixTrie{
	public:
		TrieNode *root;
		char endSymbol;

		SuffixTrie(string str){
			this->root = new TrieNode();
			this->endSymbol = endSymbol;
			this->populateSuffixTrie(str);
		};

		void populateSuffixTrie(string str){
			for(int i = 0; i < str.length(); i++){
				addSubString(i, str);
			};
		};

		void addSubString(int idx, string str){
			TrieNode *tempNode = this->root;
			for(int i = idx; i < str.length(); i++){
				if(tempNode->children.find(str[i]) == tempNode->children.end()){
					TrieNode *newNode = new TrieNode();
					tempNode->children.insert({str[i], newNode});
				};
				tempNode = tempNode->children[str[i]];
			};
			tempNode->children.insert({this->endSymbol, nullptr});
		};

		bool contain(string str){
			TrieNode *tempNode = this->root;
			for(int i = 0; i < str.length(); i++){
				if(tempNode->children.find(str[i]) == tempNode->children.end()){
					return false;
				};
				tempNode = tempNode->children[str[i]];
			};
			// to make sure that the the str is indeed in the trie, preventing scenarios like searching 'ab' in 'babc'
			return tempNode->children.find(this->endSymbol) != tempNode->children.end();
		}
}