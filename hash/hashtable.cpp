#include <list>
#include <iostream>
#include <cstring>
using namespace std;

class HashTable{
	public:
		bool isEmpty() const;
		void insertItem(int key, string value);
		void deleteItem(int key, string value);
		string seatchTable(int key);
		int hashFunc(int key);
	private:
		static const int hashGroupSize = 10;
		list<pair<int, string>> hashTable[hashGroupSize];	
};

bool HashTable::isEmpty() const {
	int sum;
	for(int i; i<hashGroupSize;i++){
		sum += hashTable[i].size();
	};
	return sum == 0;
};

int HashTable::hashFunc(int key){
	return key % hashGroupSize;
};

void HashTable::insertItem(int key, string value){
	int hashedValue = hashFunc(key);
	auto& bucket = hashTable[hashedValue];
	bool hasKey = false;
	for(auto i = bucket.begin(); i != bucket.end(); i++){
		if(key == i->first){
			i->second = value;
			hasKey = true;
			break;
		};
	};
	if(!hasKey){
		bucket.emplace_back(key, value);
	};
};

void HashTable::deleteItem(int key, string value){
	int hashedValue = hashFunc(key);
	auto& bucket = hashTable[hashedValue];
	bool hasKey = false;
	for(auto i = bucket.begin(); i != bucket.end(); i++){
		if(key == i->first){
			bucket.erase(i);
			hasKey = true;
			break;
		};
	};
};

int main(){
	return 0;
}