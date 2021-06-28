#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* input_level_wise_BT(){

    int root_data;
    queue<BinaryTreeNode<int>*> q_pending_nodes;

    cout << "Enter root data: ";
    cin >> root_data;

    if(root_data == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root_node = new BinaryTreeNode<int>(root_data);

    q_pending_nodes.push(root_node);


    while(q_pending_nodes.empty() == false){

        int node_data;

        BinaryTreeNode<int>* pending_node = q_pending_nodes.front();
        q_pending_nodes.pop();

        
        cout << "Enter Left Node of " << pending_node->data << ": ";
        cin >> node_data;

        if(node_data != -1){
            BinaryTreeNode<int>* left_node = new BinaryTreeNode<int>(node_data);

            pending_node->left = left_node;

            q_pending_nodes.push(left_node);
        }

        
        cout << "Enter Right Node of " << pending_node->data << ": ";
        cin >> node_data;
        
        if(node_data != -1){
            BinaryTreeNode<int>* right_node = new BinaryTreeNode<int>(node_data);

            pending_node->right = right_node;
            
            q_pending_nodes.push(right_node);
        }
    }

    return root_node;
}


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


int main(){

    BinaryTreeNode<int>* root_node = input_level_wise_BT();

    print_BT(root_node);

    return 0;
}