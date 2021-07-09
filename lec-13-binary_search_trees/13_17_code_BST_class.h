#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

class BST {

    private:
        BinaryTreeNode<int>* root; 

    public:
        BST() { 
            this->root = NULL;
        }

        ~BST(){

            /*
            - Since root is of BinaryTreeNode type its desctructor will take care of
              deleting children of BST.
            */

            delete this->root;
        }

    //------------------------------------------------------
    
    private:    
        BinaryTreeNode<int>* helper_insert(BinaryTreeNode<int>* root_node, int data){

            BinaryTreeNode<int>* new_node = new BinaryTreeNode<int>(data);

            // 1. Base Case
            if(root_node == NULL){
                return new_node;
            }

            // 2. Current & Recursive Case
            if(data <= root_node->data){
                root_node->left = helper_insert(root_node->left, data);
            } else {
                root_node->right = helper_insert(root_node->right, data);
            }

            return root_node;
        }

    public:    
        void insert(int data) { 
            this->root = helper_insert(this->root, data);
        }


    //------------------------------------------------------

    private:
        BinaryTreeNode<int>* minimum_node(BinaryTreeNode<int>* root_node){
            
            // 1. Base Case
            if(root_node == NULL){
                return NULL;
            }

            // 2. Current
            if( (root_node->left == NULL) && (root_node->right == NULL) ){
                return root_node;
            }
            
            // 3. Recursive Case
            if(root_node->left != NULL){
                return minimum_node(root_node->left);
            } else {
                // return minimum_node(root->right);
                return root_node;
            }
            
        }
        
        
        BinaryTreeNode<int>* helper_remove(BinaryTreeNode<int>* root_node, int data){
            
            // 1. Base Case
            if(root_node == NULL){
                return NULL;
            }


            // 2. Current Problem
            if(root_node->data == data){

                // 2.1 If the root is a leaf node
                if( (root_node->left == NULL) && (root_node->right == NULL) ){
                    delete root_node;
                    return NULL;
                }

                // 2.2 If the root has a single child.
                if( (root_node->left == NULL) && (root_node->right != NULL) ){
                    // [#important]
                    // delete root; // This will delete the entire right sub-tree

                    BinaryTreeNode<int>* temp_node = root_node->right;
                    root_node->right = NULL;
                    delete root_node;

                    return temp_node;
                }

                if( (root_node->left != NULL) && (root_node->right == NULL) ){
                    // [#important]
                    // delete root; // This will delete the entire left sub-tree

                    BinaryTreeNode<int>* temp_node = root_node->left;
                    root_node->left = NULL;
                    delete root_node;

                    return temp_node;
                }

                // [#important] 2.3 If the root has two children.
                /*
                - Find a replacement node in one of the children.
                    - Repalcement = Smallest Element in Right Subtree. OR
                    - Replacement = Largest Element in Left Subtree.
                
                - Replace (root->data) with (replacement->data).

                - Delete replacement node.
                */
                if( (root_node->left != NULL) && (root_node->right != NULL) ){
                    
                    // BinaryTreeNode<int>* replacement_node = minimum_node(root_node->right);

                    // Keep going left till you encounter NULL
                    BinaryTreeNode<int>* replacement_node = root_node->right;
                    while(replacement_node->left != NULL){
                        replacement_node = replacement_node->left;
                    }

                    root_node->data = replacement_node->data;

                    root_node->right = helper_remove(root_node->right, replacement_node->data);

                    return root_node;
                }
            }


            // 3. Recursive Case
            if(root->data < data){
                root_node->right = helper_remove(root_node->left, data);
            } else {
                root_node->left =  helper_remove(root_node->right, data);
            }

            return root_node;
        }

    public:    
        void remove(int data) { 
            this->root = helper_remove(this->root, data); 
        }
    

    //------------------------------------------------------

    private:
        void helper_print(BinaryTreeNode<int>* root_node){
            
            if (root_node == NULL) {
				return;
            }
            cout << root_node->data << ":";
            
            if (root_node->left != NULL) {
                cout << "L:" << root_node->left->data << ",";
            }

            if (root_node->right != NULL) {
                cout << "R:" << root_node->right->data;
            }
            cout << endl;
            
            helper_print(root_node->left);
            helper_print(root_node->right);
        }


    public:
        void print() { 
            helper_print(this->root);
        }

        
    //------------------------------------------------------
    
    private:    
        bool helper_search(BinaryTreeNode<int>* root_node, int data){

            bool ans;

            // 1. Base Case
            if(root_node == NULL){
                return false;
            }

            
            // 2. Current Problem
            if(root_node->data == data){
                return true;
            }


            // 3. Recursive Case
            if(data < root_node->data){
                ans = helper_search(root_node->left, data);
            } else {
                ans = helper_search(root_node->right, data);
            }
            
            return ans;
        }

    public:    
        bool search(int data) {
            return (helper_search(this->root, data));
        }
};