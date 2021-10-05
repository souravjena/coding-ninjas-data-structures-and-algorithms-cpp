#include <iostream>
#include <string>
#include <vector>
#include "16_3_implementation_tries.h"
using namespace std;


int main(){
	
	Trie t;
	vector<string> vec = {"abc", "def", "ghi", "hg"};

	cout << t.patternMatching(vec, "hx") << endl;
	cout << t.patternMatching(vec, "hi") << endl;
	cout << t.patternMatching(vec, "de") << endl;

	return 0;
}