using namespace std;
#include <vector>
#include <unordered_map>
#include <string>
class MinMaxStack{
	public:
		vector<unordered_map<string, int>> minMaxStack={};
		vector<int> stack={};
		int peek(){
			return stack[stack.size()-1];
		};

		int pop(){
			minMaxStack.pop_back();
			int res = stack[stack.size()-1];
			stack.pop_back();
			return res;
		};

		void push(int number){
			unordered_map<string, int> newMinMax = {{"max",number},{"min",number}};
			if(stack.size() != 0){
				unordered_map<string, int> lastMinMax = minMaxStack[stack.size()-1];
				newMinMax["min"] = min(number, lastMinMax["min"]);
				newMinMax["max"] = max(number, lastMinMax["max"]);
			};
			minMaxStack.push_back(newMinMax);
			stack.push_back(number);
		};

		int getMax(){			
			return minMaxStack[minMaxStack.size()-1]["max"];
		};

		int getMin(){
			return minMaxStack[minMaxStack.size()-1]["min"];
		};

};