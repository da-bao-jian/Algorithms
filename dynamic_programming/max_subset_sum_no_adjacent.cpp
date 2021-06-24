//write a function that takes in an array of positiv eintegers and returns the maximum sum of non adjacent alements in the array;
// if the input array is empy, the function should return 0

#include <vector>
#include <iostream>
using namespace std;
int maxSubsetSumNoAdjacent(vector<int> array){
	if(array.size() == 0){
		return 0;
	} else if(array.size() == 1){
		return array[0];
	};

	int * maxSum = &array[0];
	maxSum[1] = max(array[0], array[1]);
	for(int i = 2; i < array.size(); i++){
		maxSum[i] = max(array[i-1], array[i-2]+array[i]);
	};
	return maxSum[array.size()-1];
};

int main(){
	vector<int> array = {1,2,3,4,5};
	maxSubsetSumNoAdjacent(array);
}