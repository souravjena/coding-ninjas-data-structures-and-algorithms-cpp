#include <iostream>
#include <climits>
using namespace std;


int countMinStepsToOne(int n){
	
	int a = INT_MAX; 
	int b = INT_MAX;
	int c = INT_MAX;

	// 1. Base Case
	if(n == 1){
		return 0;
	}

	// 2. Recursive Case
	if(n%3 == 0){
		a = countMinStepsToOne(n/3);
	}

	if(n%2 == 0){
		b = countMinStepsToOne(n/2);
	}

	c = countMinStepsToOne(n-1);


	// 3. Current Problem
	return (1 + min(a, min(b, c)));

}


int main(){

	cout << countMinStepsToOne(7) << endl;

	return 0;
}