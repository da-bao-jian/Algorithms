#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array){
	if(array.empty()){
		return {};
	};
	bool sorted = false;
	int counter = 0;
	//optimization to not run the entire loop each time, since after each iteration, the largest element in this iteration will be put to the end 
	while(!sorted){
		sorted = true;
		for(int i = 0; i < array.size()-1 - counter; i++){
			if(array[i]>array[i+1]){
				swap(array[i],array[i+1]);
				sorted = false;
			};
		}
	}
	counter ++;
};