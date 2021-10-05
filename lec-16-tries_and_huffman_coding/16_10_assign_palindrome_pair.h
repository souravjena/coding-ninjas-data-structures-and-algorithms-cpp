#include <bits/stdc++.h>

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */
    
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

    
    
    
    bool isPalindromePair(vector<string> words) {
        // Write your code here
        
        int initial_size = words.size();
        
        // 1. Add all combination of two words in the vector.
        for(int i = 0; i < initial_size; i++){
            for(int j = 1; j < initial_size; j++){
                string combined = words.at(i) + words.at(j);
                words.push_back(combined);
            }
        }
        
        
        // 2. Search for Palindrome Pair
        for(int i = 0; i < words.size(); i++){
            string wrd = words.at(i);
            
            string reverse_wrd = "";
            reverse_wrd = wrd;
            reverse(reverse_wrd.begin(), reverse_wrd.end());
            
            // cout << reverse_wrd << "\t" << wrd << endl;
            
            if(wrd.compare(reverse_wrd) == 0){
                    return true;
            }
            
            if(this->search(wrd) == true){
                if(wrd.compare(reverse_wrd) == true){
                    return true;
                }
            }
            
            if(this->search(reverse_wrd) == true){
                if(wrd.compare(reverse_wrd) == true){
                    return true;
                }
            }
            
            this->add(wrd);
            this->add(reverse_wrd);
        }
        
        return false;
    }
};