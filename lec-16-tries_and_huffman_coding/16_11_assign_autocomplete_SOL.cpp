class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
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

    bool insertWord(TrieNode *root, string word) {
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
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    
    
    //-------------------------------------------------------
    
    
    // ** important **
    TrieNode* search(TrieNode* curr_node, string word){

        // 1. Base Case
        if(word.size() == 0){
   			return curr_node;
        }


        // 2. Current Problem
        int index_char = word[0] - 'a';		// Assuming all input words are in lowercase.

        TrieNode* child_node = curr_node->children[index_char];

        if(child_node == NULL){
            return child_node;
        } 


        // 3. Recursive Case
        TrieNode* ans = search(child_node, word.substr(1));
        return ans;
    }

    TrieNode* search(string word){
        return search(this->root, word);
    }
    
    
	
    
    
    
    //-------------------------------------------------------
	// Solution from here.
	//-------------------------------------------------------
    void print(TrieNode *root, string s) {
        
        if (root == NULL) {
        	return;
        }

        
        if (root->isTerminal) {
        	cout << s << endl;
        }

        
        for (int i = 0; i < 26; ++i) {
            if (root->children[i]) {
            	string t = s + root->children[i]->data;
            	print(root->children[i], t);
            }
        }
    }
    
    
	
	void printAllPossibleWords(TrieNode* curr_node, string pattern, string output){
        
        // 1. Base Case
        if(curr_node == NULL){
            return;
        }
        
        // 2. Current Case
        if(pattern.size() == 0){
            if(curr_node->isTerminal == true){
        		cout << output << endl;
            }

            for(int i = 0; i < 26; i++){
                TrieNode* child_node = curr_node->children[i];

                if(child_node != NULL){
                    string updated_output = output + child_node->data;
                    this->print(child_node, updated_output);
                }
            }
            
            return;
        }
        
        // 3. Recursive Problem
        int index = pattern[0] - 'a';
		output += pattern[0];
		printAllPossibleWords(curr_node->children[index], pattern.substr(1), output);

        
        return; 
    }
    
    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        
        // 1. Insert all the words in the trie.
        for(int i = 0; i < input.size(); i++){
            this->insertWord(input.at(i));
        }
        

        string output = "";
        printAllPossibleWords(this->root, pattern, output);
         
        
    }
};