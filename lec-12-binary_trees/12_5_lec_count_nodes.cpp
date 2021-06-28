#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;


/**
 * @brief [#BT, #recursion] [12.5 L] Count number of nodes in a BT.
 * 
 * @param root Address of root node of the BT.
 * @return int Number of nodes in the BT.
 */
int count_nodes_BT(BinaryTreeNode<int>* root){

    // Base Case
    if(root == NULL){
        return 0;
    }

    // Current and Recursive Case
    return (1 + count_nodes_BT(root->left) + count_nodes_BT(root->right));
}



/**
 * @brief Print Binary Tree Level-Wise.
 * 
 * @param root Address of root node of the Binary Tree.
 */
void printLevelWise(BinaryTreeNode<int> *root) {

    queue<BinaryTreeNode<int>*> q;

    // Edge Case
    if(root == NULL){
        return;
    }

    q.push(root);

    while(q.empty() == false){

        BinaryTreeNode<int>* pending_node = q.front();
        q.pop();

        cout << pending_node->data << ":";

        if(pending_node->left == NULL){
            cout << "L:" << -1 << ",";
        } else {
            cout << "L:" << pending_node->left->data << ",";
            q.push(pending_node->left);
        }
        
        
        if(pending_node->right == NULL){
            cout << "R:" << -1;
        } else {
            cout << "R:" << pending_node->right->data;
            q.push(pending_node->right);
        }

        cout << endl;
    }
}


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




int main(){

    BinaryTreeNode<int>* root_node = input_level_wise_BT();

    printLevelWise(root_node);

    cout << endl << "Number of nodes: " << count_nodes_BT(root_node) << endl;

    return 0;
}