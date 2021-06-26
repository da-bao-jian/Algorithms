using namespace std;
class LinkedList{
	public:
		int value;
		LinkedList *next = nullptr;
		LinkedList(int value){ this->value = value;}
};

LinkedList *removeDuplicate(LinkedList *linkedList){
	LinkedList *ll = linkedList;
	while(ll != nullptr){
		LinkedList *nonDupLL = ll->next; 
		while(nonDupLL != nullptr && nonDupLL->value == ll->value){
			nonDupLL = nonDupLL->next;
		};
		ll->next = nonDupLL;
		ll = nonDupLL;
	}
	return linkedList;
}