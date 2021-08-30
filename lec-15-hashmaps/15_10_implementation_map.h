#include <string>
using namespace std;

// Linked-List Class
template <typename T>
class MapNode {

	public:
		string key;
		T value;
		MapNode* next;
	
		// Constructor
		MapNode(string key, T value){
			this->key = key;
			this->value = value;
			this->next = NULL;
		}

		// Destructor
		~MapNode(){
			// **[#important]** Recursively delete all the elements in the LL.
			delete (this->next);
		}
};


// Map Class
template <typename T>
class MyMap {

	private:
		MapNode<T>** arr_bucket;
		int total_nodes;
		int total_buckets;

	public:
		// Constructor
		MyMap(){
			this->total_nodes = 0;
			this->total_buckets = 5;

			this->arr_bucket = new MapNode<T>*[this->total_buckets];

			/*
			- arr_bucket will have garbage values after its creation.
			- So, we need to clean it before using it.
			*/
			for(int i = 0; i < total_buckets; i++){
				arr_bucket[i] = NULL;
			}
		}

		// Destructor
		~MyMap(){
			// 1. Delete all the LLs.
			for(int i = 0; i < total_buckets; i++){
				delete arr_bucket[i];	// This will recursively delete the entire LL.
			}

			// 2. Delete arr_bucket
			delete [] arr_bucket;
		}



		//_________________________________________________________________
		//_________________________________________________________________

	private:
		// ** [#important] **
		// Returns bucket-index for a given key.
		int hash_function(string key){
			
			// 1. Generate a hash-code from the key.
			int hash_code = 0;

			// ** [#important] Modular Exponentiation ** [footnotes]
			int curr_coff = 1;
			for(int i = (key.length() - 1); i >= 0; i--){
				hash_code += key[i] * curr_coff;
				hash_code = hash_code % total_buckets;

				curr_coff = (curr_coff * 37) % total_buckets;
			}

			// 2. Pass the hash-code through Compression Function.
			return (hash_code % total_buckets);
		}



		void rehash(){
			cout << "Rehasing!" << endl;
			
			// 1. Store old bucket
			MapNode<T>** old_arr_bucket = this->arr_bucket;
			int old_total_buckets = this->total_buckets;

			// 2. Create new bucket & make it the defualt bucket for the hashmap
			this->arr_bucket = new MapNode<T>*[2 * this->total_buckets];
			this->total_buckets = 2 * this->total_buckets;
			this->total_nodes = 0;	// We are going to call insert() which will automatically update it later.

			for(int i = 0; i < (this->total_buckets); i++){
				this->arr_bucket[i] = NULL;
			}


			// 3. Copy elements from old to new bucket
			for(int j = 0; j < old_total_buckets; j++){

				MapNode<T>* curr_node = old_arr_bucket[j];

				while(curr_node != NULL){
					string key = curr_node->key;
					T value = curr_node->value;
					this->insert(key, value);

					curr_node = curr_node->next;
				}
			}


			// 4. Delete the old bucket array and its nodes
			for(int k = 0; k < old_total_buckets; k++){
				delete old_arr_bucket[k];
			}
			delete [] old_arr_bucket;
		}

	
	
	public:
		int size(){
			return (this->total_nodes);
		}


		T getValue(string key){
			// 1. Get bucket index.
			int bucket_index = this->hash_function(key);

			// 2. Get head of the LL at that location.
			MapNode<T>* curr_node = this->arr_bucket[bucket_index];

			// 3. Traverse through the LL.
			while(curr_node != NULL){
				if(curr_node->key == key){
					return (curr_node->value);
				}

				curr_node = curr_node->next;
			}
			
			return 0;
		}

		double getLoadFactor(){
			return ( (1.0*this->total_nodes)/this->total_buckets);
		}


		// ** [#important] **
		void insert(string key, T value){
			// 1. Get bucket index.
			int bucket_index = this->hash_function(key);

			// 2. Get head of the LL at that location.
			MapNode<T>* curr_node = this->arr_bucket[bucket_index];

			// 3. If head at index != NULL, then traverse through the LL.
			while(curr_node != NULL){
				
				// 3.1 If key is there already in the LL then just update its value and return.
				if(curr_node->key == key){
					curr_node->value = value;
					return;
				}
				
				curr_node = curr_node->next;
			}

			// 3.2 If the key is not in the LL then create a MapNode and insert it as the head of LL.
			MapNode<T>* new_node = new MapNode<T>(key, value);
			MapNode<T>* old_head = this->arr_bucket[bucket_index];
			
			new_node->next = old_head;					// attach old-head to new node.
			this->arr_bucket[bucket_index] = new_node;	// place new node as head in the bucket.
			
			this->total_nodes++;						// update total number of nodes in the Map.

			// 4. If required do ** Rehashing **.
			// Let do rehasing if loadFactor >= 0.7.
			double load_factor = (1.0 * this->total_nodes)/this->total_buckets;

			if(load_factor >= 0.7){
				this->rehash();	
			}
					
		}





		// ** [#important] **
		T remove(string key){
			// 1. Get bucket index.
			int bucket_index = this->hash_function(key);

			// 2. Get head of the LL at that location.
			MapNode<T>* curr_node = this->arr_bucket[bucket_index];

			// 3. We need prev_node also because we would have to connect
			// prev_node with curr_node->next in order to remove curr_node.
			MapNode<T>* prev_node = NULL;

			// 4. Traverse through LL
			while(curr_node != NULL){
				
				if(curr_node->key == key){
					
					// 4.1 If key is the head of the LL.
					if(prev_node == NULL){
						this->arr_bucket[bucket_index] = curr_node->next;
					} else {
						prev_node->next = curr_node->next;
					}

					// 4.2 Before deleting the current node we need to make curr_node->next = NULL
					// or else the destructor will delete all the nodes from curr_node to tail of LL.					
					T removed_value = curr_node->value;
					curr_node->next = NULL;
					delete curr_node;

					this->total_nodes--;
					
					return removed_value;
				}
				
				// 4.3 Update
				prev_node = curr_node;
				curr_node = curr_node->next;
			}

			return 0;	// Signifies that we didn't get the key to be removed.
		}
};


// ** Foot Notes **

/* ** Modular Exponentiation **
	- hash_function("abc") = [('a' * p^2) + ('b' * p^1) + ('c' * p^0)] % total_buckets

	- But if string length is large like 15 and p is big like 37
	- Then, computing 37^15 will be very difficult and might not be possible also.
	- To overcome this we can use  ** Modular Exponentiation ** which will ensure that,
		intermediate results don't go beyond certain limit.
	- According to ** Modular Exponentiation **
		[p*p*p] % r = [ (((p%r)*p)%r*p)%r ] % r
	- URL: https://stackoverflow.com/questions/50181801/c-hashcode-working-with-large-numbers-mod-operation
	- URL: https://en.wikipedia.org/wiki/Modular_exponentiation
*/