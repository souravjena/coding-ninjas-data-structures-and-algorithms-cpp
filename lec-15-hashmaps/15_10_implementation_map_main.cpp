#include <iostream>
#include <string>
#include "15_10_implementation_map.h"
using namespace std;

int main(){

	MyMap<int> hashmap;

	/*
	initial bucket size = 5
	load_factor = 0.7
	*/
	cout << "Key \t Value \t Load_Factor \t Size"  << endl;

	for(int i = 0; i < 10; i++){
		char c = ('0' + i);
		string key = "abc";
		key += c;
		int value = i;
		
		hashmap.insert(key, value);
		cout << key << "\t   " << value << "\t   " << hashmap.getLoadFactor() << "\t\t" << hashmap.size() << endl;
	}


	cout << endl << endl;

	cout << hashmap.size() << endl;
	cout << hashmap.getValue("abc2") << endl;
	hashmap.remove("abc2");
	cout << hashmap.size() << endl;
	cout << hashmap.getValue("abc2") << endl;

	return 0;
}