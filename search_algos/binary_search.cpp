#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target, int first, int last){
	if(first > last){
		return -1;
	};
	int mid = (first + last) / 2;
	if(target == array[mid]){
		return mid;
	} else if (target < array[mid]) {
		return binarySearch(array, target, first, mid-1);
	} else {
		return binarySearch(array, target, mid+1, last);
	};
};