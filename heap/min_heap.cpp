//题点：children nodes are 2*currentIdx +1 and 2*currentIdx + 2, and parent node is floor(i-1/2)
#include <vector>
using namespace std;

class minHeap{
	public:
		vector<int> heap;
		minHeap(vector<int> vector) { heap = buildHeap(vector);};

		
		vector<int> buildHeap(vector<int> &vector){ 
			int firstParentIdx = (vector.size()-1)/2;
			for(int i = firstParentIdx; i >= 0; i--){
				siftDown(i, vector.size()-1, vector);
			}
			
		};

		void siftDown(int currentIdx, int endIdx, vector<int> &heap){
			int leftChildIdx = currentIdx * 2 + 1;
			while(leftChildIdx <= endIdx){
				int smallerIdx;
				int rightChildIdx = currentIdx * 2 + 2;
				if(rightChildIdx <= endIdx){
					smallerIdx = heap[rightChildIdx] > heap[leftChildIdx] ? leftChildIdx : rightChildIdx;
					if(heap[smallerIdx] < heap[currentIdx]){
						swap(heap[currentIdx], heap[smallerIdx]);
						currentIdx = smallerIdx;
						leftChildIdx = currentIdx *2 + 1;
					} else {
						return;
					};
				} else {
					smallerIdx = heap[leftChildIdx];
					if(heap[smallerIdx] < heap[currentIdx]){
						swap(heap[currentIdx], heap[smallerIdx]);
						currentIdx = smallerIdx;
						leftChildIdx = currentIdx *2 + 1;
					} else {
						return;
					};
				}
			}
		};

		void siftUp(int currentIdx, vector<int> &heap){
			int parentIdx = currentIdx-1/2;
			while(parentIdx >= 0 && heap[currentIdx] < heap[parentIdx]){
				swap(heap[parentIdx], heap[currentIdx]);
				currentIdx = parentIdx;
				parentIdx = currentIdx-1/2;
			};
		};

		int remove(){
			// swap head and tail => siftDown the new head to the proper location
			// will cal the siftDown()
			swap(heap[0], heap[heap.size()-1]);
			int res = heap[heap.size()-1];
			heap.pop_back();
			siftDown(0, heap.size()-1, heap);
			return res;
		};

		void insert(int value){
			// will call the siftUp()
			heap.push_back(value);
			siftUp(heap[heap.size()-1]);
		};

		int peek(){
			return heap[0];
		};

};
