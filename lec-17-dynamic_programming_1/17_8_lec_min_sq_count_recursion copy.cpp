#include <iostream>
#include <cmath>
using namespace std;

int minCount_resursive(int n){
	//Write your code here

	// Max value of answer could be n the number itself; 3 = 1^2 + 1^2 + 1^2
	int ans = n;

	// 1. Base Case
	// If the number is perfect square return 1; n = 144 = 12^2, ans = 1
	if(sqrt(n) == floor(sqrt(n))){
		return 1;
	}

	// 2. Recursive Case
	for(int i = 1; i < sqrt(n); i++){
		int sub_ans = 1 + minCount_resursive(n - (i*i)); // 2^2 + func(n - (2^2)); ans = 1 + ans_of[func(n - (2^2))]

		ans = min(ans, sub_ans);
	}

	// 3. Current Problem
	return ans;
}


int main(){

	cout << minCount_resursive(10) << endl;

	return 0;
}