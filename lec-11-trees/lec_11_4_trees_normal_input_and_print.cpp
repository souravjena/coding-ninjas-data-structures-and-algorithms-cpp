#include <iostream>
#include "TreeNode.h"
using namespace std;


/*
    TreeNode<int>* takeInput()

    - Function to take input from the user and connect the nodes to form a tree.
    - Return: Address of the root node.
*/
TreeNode<int>* takeInput(){

    int data_node;
    int number_child;

    cout << "Enter node data: ";
    cin >> data_node;
    TreeNode<int> *node_root = new TreeNode<int>(data_node);

    cout << "Enter # of children of this [" << data_node << "] node: ";
    cin >> number_child;

    for(int i = 0; i < number_child; i++){
        TreeNode<int> *node_child = takeInput();
        node_root->children.push_back(node_child);
    }

    return node_root;
}


/*
    void printTree(TreeNode<int>* root)

    - Function to print a tree.
    - Argument: root node's pointer.
    - Return: NA
*/

void printTree(TreeNode<int>* root){

    // Edge Case (not the Base Case)
    if(root == NULL){
        return;
    }

    // 1. Current Problem
    cout << root->data << ": ";

    /* 
        ** Base Case **
        - If there are no children of the current node then return.
        - There is no need to explicity write this base case since
          the program won't enter the for loops if root->children.size() == 0
    */
    for(int i = 0; i < root->children.size(); i++){
        cout << (root->children.at(i))->data << ", ";
    }
    cout << endl;

    // 3. Recursive Case
    for(int j = 0; j < root->children.size(); j++){
        printTree(root->children.at(j));
    }

}

int main(){

    TreeNode<int>* node_root = takeInput();

    printTree(node_root);

    return 0;
}