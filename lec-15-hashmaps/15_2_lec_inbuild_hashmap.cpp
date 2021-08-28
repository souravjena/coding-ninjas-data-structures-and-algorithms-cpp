#include <iostream>
#include <unordered_map>	// For Hashmaps
#include <string>
using namespace std;

int main(){
	//<key_type, value_type>
	unordered_map<string, int> hashmap;

	// ** 1. Insert **
	// 1.1 Using pair
	pair<string, int> key_val_pair("mango", 2);
	hashmap.insert(key_val_pair);

	// 1.2 Using [] operator
	hashmap["apple"] = 3;


	
	// ** 2. Find/Access **
	// 2.1 Using .at() method.
	cout << "Apple = " << hashmap.at("apple") << endl;

	// 2.2 Using [] operator
	cout << "Mango = " << hashmap["mango"] << endl;


	/* ** If a key doesnot exist and we try to access it. **
	- .at() will throw an error.
	- But [] won't throw an error instead it will insert that key
	  with a default value of 0;
	*/
	// cout << "Random = " << hashmap.at("random") << endl;
	cout << "Random = " << hashmap["random"] << endl;



	// ** 3. Size **
	cout << "Size = " << hashmap.size() << endl;


	// ** 4. Check Presense and Absence of a key **
	/*
	- Only one unique key is possible in a hashmap.
	- So .cout() function will return either 0 or 1.
	*/

	if(hashmap.count("apple") == 1){
		cout << "apple is present." << endl;
	}

	if(hashmap.count("orange") == 0){
		cout << "orange is absent." << endl;
	}


	// ** 5. Remove/Erase a Key-Value pair from a hashmap.
	cout << "Size before erase = " << hashmap.size() << endl;

	hashmap.erase("random");
	hashmap.erase("apple");

	cout << "Size after erase = " << hashmap.size() << endl;

	return 0;
}
