#include <iostream>
#include <unordered_map>	// For Hashmaps
#include <map>				// For Ordered Map (BST)
#include <vector>
#include <string>		
using namespace std;

int main(){

	unordered_map<string, int> hashmap;
	unordered_map<string, int>::iterator it;	// Iterator for the Hashmap

	hashmap["key0"] = 0;
	hashmap["key1"] = 1;
	hashmap["key2"] = 2;
	hashmap["key3"] = 3;
	hashmap["key4"] = 4;

	/*
	- Each row of the hashmap is a pair<string, int> class.
	- The iterator points to the address of the object of this pair class.
	*/
	cout << "Unordered Map (Hashmap)" << endl;

	for(it = hashmap.begin(); it != hashmap.end(); it++){
		cout << "Key: " << it->first << "\t";
		cout << "Value: " << it->second << endl;
	}
	cout << endl << endl;


	//_____________________________________________________________
	
	map<string, int> my_map;
	map<string, int>::iterator it2;	// Iterator for the map

	my_map["key0"] = 0;
	my_map["key1"] = 1;
	my_map["key2"] = 2;
	my_map["key3"] = 3;
	my_map["key4"] = 4;

	cout << "Ordered Map (BST)" << endl;

	for(it2 = my_map.begin(); it2 != my_map.end(); it2++){
		cout << "Key: " << it2->first << "\t";
		cout << "Value: " << it2->second << endl;
	}
	
	cout << endl << endl;

	//_____________________________________________________________


	vector<int> v;
	vector<int>::iterator it3;	// Iterator for the map

	v = {0, 1, 2, 3, 4};

	cout << "Vector" << endl;

	for(it3 = v.begin(); it3 != v.end(); it3++){
		cout << *it3 << endl;
	}


	return 0;
}