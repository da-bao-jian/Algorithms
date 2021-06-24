#include <list>
#include <iostream>
#include <cstring>
using namespace std;

class HashTable{
	public:
		bool isEmpty() const;
		void insertItem(int x);
		void deleteItem(int key);
		string seatchTable(int key);
		int hashFunc(int key);


	private:
		static const int hashGroupSize = 10;
		list<pair<int, string>> hashGroup[hashGroupSize];	
};

bool HashTable::isEmpty() const {
	int sum;
	for(int i; i<hashGroupSize;i++){
		sum += hashGroup[i].size();
	};
	return sum == 0;
};

int main(){
	return 0;
}