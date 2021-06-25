//write a function that takes in a non empy array of integers and returns the maximum sum that can be obtained by summing up all
// of the integers in a non-empy subarray of the input array. A subarray must only contain adjacent numbers(numbers nest to each other in the input array)
// array =[3,5,-9,1,3,-2,3,4,7,2,-9,6,3,1,-5,4]
//output = 19 sum of 1,3,-2,3,4,7,2,-9,6,3,1


#include <vector>
using namespace std;

//题点: use Kadane Algorithm
//	in a loop, compare the sum of current index number + previous number with the previous number, and add whichever one is greater 

int maximumSumSubarray(vector<int> array){
	int maximum = array[0];
	int counter = 0;
	for(int i:array){
		counter = i >= counter+i ?  i : counter +i;
		maximum = maximum > counter ? maximum : counter;
	};
	return maximum;
}