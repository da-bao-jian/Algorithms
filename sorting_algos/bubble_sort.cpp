#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array){
	if(array.empty()){
		return {};
	};
	bool sorted = false;
	
	while(!sorted){
		sorted = true;
		for(int i = 0; i < array.size()-1; i++){
			if(array[i]>array[i+1]){
				swap(array[i],array[i+1]);
				sorted = false;
			};
		}
	}
};