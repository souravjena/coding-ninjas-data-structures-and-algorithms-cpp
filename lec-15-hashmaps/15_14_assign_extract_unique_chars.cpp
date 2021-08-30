#include <iostream>
#include <unordered_map>	// For Hashmaps
#include <string>
using namespace std;

string uniqueChar(string str) {
	// Write your code here

	unordered_map<char, int> hashmap;
	string ans = "";

	for(int i = 0; i < str.length(); i++){
		if(hashmap.count(str[i]) == 0){
			ans += str[i];
			hashmap[str[i]] = 1;		
		}
	}

	return ans;
}

int main(){

	string input = "ababacd";
	string output = uniqueChar(input);

	cout << output << endl;

	return 0;
}