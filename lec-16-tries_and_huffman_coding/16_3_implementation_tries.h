#include "16_3_implementation_tries_node.h"
#include <string>
using namespace std;

class Trie{

	private:
		TrieNode* root;

	public:
		Trie(){

			root = new TrieNode('\0');

		}


		// ** important **
		void insertWord(TrieNode* curr_node, string word){

			// 1. Base Case
			if(word.size() == 0){
				curr_node->isTerminal = true;
				return;
			}


			// 2. Current Problem
			int index_char = word[0] - 'a';		// Assuming all input words are in lowercase.

			TrieNode* child_node = curr_node->children[index_char];

			if(child_node == NULL){
				TrieNode* new_node = new TrieNode(word[0]);
				curr_node->children[index_char] = new_node;
				child_node = new_node;
			}


			// 3. Recursive Case
			insertWord(child_node, word.substr(1));

		}

		void insertWord(string word){
			insertWord(this->root, word);
		}

		
		
		// ** important **
		bool search(TrieNode* curr_node, string word){

			// 1. Base Case
			if(word.size() == 0){
				// This means that the word ends here.
				// So we need to check if the current node is a terminal node or not.
				if(curr_node->isTerminal == true){
					return true;
				} else {
					return false;
				}
			}

			
			// 2. Current Problem
			int index_char = word[0] - 'a';		// Assuming all input words are in lowercase.

			TrieNode* child_node = curr_node->children[index_char];

			if(child_node == NULL){
				return false;
			} 
				
			
			// 3. Recursive Case
			bool ans = search(child_node, word.substr(1));
			return ans;
		}

		bool search(string word){
			return search(this->root, word);
		}



		// ** important **
		void removeWord(TrieNode* curr_node, string word){

			// 1. Base Case
			if(word.size() == 0){
				// Make the final char of the word to be deleted, non-terminating
				curr_node->isTerminal = false;
				return;
			}


			// 2. Current Problem
			int child_index = word[0] - 'a';

			TrieNode* child_node = curr_node->children[child_index];

			if(child_node == NULL){
				return;
				// This indicates that the word to be removed is not there in the trie.
			}


			// 3. Recursive Case
			removeWord(child_node, word.substr(1));


			// 4. Post Recursion
			/*
			- Now that isTerminal flag is removed from terminating node
			- we can delete the child node if it is not a terminating node for some other word and
			- it does not have any children which would otherwise suggest that this node 
			  is part of some other word in the trie.
			*/

			if(child_node->isTerminal == false){

				for(int i = 0; i < 26; i++){
					if(child_node->children[i] != NULL){
						return;
					}
				}

				delete child_node;

				curr_node->children[child_index] = NULL;

			}

		}

		void removeWord(string word){
			removeWord(this->root, word);
		}




		// 16.9 - Assign - Pattern Matching
		bool patternMatching(vector<string> vect, string pattern) {
        	// Write your code here

			// 1. Insert all words and their substrings in the Trie
			for(int i = 0; i < vect.size(); i++){
				string word = vect.at(i);
				this->insertWord(word);

				for(int j = 0; j < word.length(); j++){
					this->insertWord(word.substr(0, j));
					this->insertWord(word.substr(j, word.length()));
				}
			}

			// 2. Search for the pattern in the trie
			return (this->search(pattern));

    	}
};