#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

vector<int> two_sum(vector<int> *array, int target){
	unordered_set<int> nums;
	for(int num: *array){
		int remainder = target - num;
		if(nums.find(remainder) != nums.end()){
			return vector<int>{remainder, num};
		} else {
			nums.insert(num);
		}
	}
	return {};
}

void print(vector<int> & arr){
	for(int i: arr){
		cout << i << " " << endl;
	}
}

int main(){
	vector<int> array = {2,3,5,12,4};
	auto res = two_sum(&array, 6);
	print(res);
	return 0;
}