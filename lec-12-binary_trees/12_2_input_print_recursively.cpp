#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

void print_BT(BinaryTreeNode<int>* root) {

    // 1. Base Case
    if(root == NULL){
        return;
    }

    // 2. Current Problem
    cout << root->data << ": ";

    if(root->left != NULL){
        cout << "L[" << root->left->data << "]\t"; 
    }

    if(root->right != NULL){
        cout << "R[" << root->right->data << "]";
    }
    
    cout << endl;
    
    // 3. Recursive Case
    print_BT(root->left);
    print_BT(root->right);
}



BinaryTreeNode<int>* input_BT() {

    int root_data;

    cout << "Enter data: ";
    cin >> root_data;

    // 1. Base Case
    if(root_data == -1){
        return NULL;
    }

    // 2. Current Problem & Recursive Case
    BinaryTreeNode<int>* root_node = new BinaryTreeNode<int>(root_data);
    
    BinaryTreeNode<int>* left_node = input_BT();
    BinaryTreeNode<int>* right_node = input_BT();

    root_node->left = left_node;
    root_node->right = right_node;

    return root_node;
}


int main(){

    BinaryTreeNode<int>* root_node = input_BT();

    print_BT(root_node);

}