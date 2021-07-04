#include <iostream>
#include <queue>
// #include "BinaryTreeNodeFn.h"
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

/**
 * @brief Print Binary Tree Level-Wise.
 * 
 * @param root Address of root node of the Binary Tree.
 */
void print_level_wise_BT(BinaryTreeNode<int> *root) {

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

void printLevelWise(BinaryTreeNode<int> *root) {
    
    BinaryTreeNode<int>* new_line_indicator = new BinaryTreeNode<int>(-1);  // Node to indicate printing of new-line
    queue<BinaryTreeNode<int>*> q;

    if(root == NULL){
        return;
    }

    /*
    - Since there is only single root of any BT, hence we are pushing root and new_line_indicator node
      so that root is printed and after that a new line.
    */
    q.push(root);
    q.push(new_line_indicator);

    // Print nodes in the q.
    while(q.empty() == false){

        // Take out the front node in the q.
        BinaryTreeNode<int>* curr_node = q.front();
        q.pop();
        
        // If new_line_indicator node is encountered print new line else the element.
        if(curr_node != new_line_indicator){
            cout << curr_node->data << " ";
        } else {
            cout << endl;

            if(q.empty() == true){
                return;
            } else {
                /*
                - ** [#important] ** 
                - When a new_line_node indicator is encountered by then we will have
                  all the child nodes at a particular level in the q already.
                - Since in each loop we are pushing all the child nodes of a node in the q.
                */
                q.push(new_line_indicator);
            }
        }

        // Push child nodes
        if(curr_node->left != NULL){
            q.push(curr_node->left);
        }

        if(curr_node->right != NULL){
            q.push(curr_node->right);
        }
    } 
}




/**
 * @brief [#BT, #recursion] Removes leaf nodes of a BT.
 * 
 * @param root Address of root node of the given BT.
 * @return BinaryTreeNode<int>* Updated root node's address.
 */
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    
    // 1. Base Case
    if(root == NULL){
        return NULL;
    }

    // 2. Current Problem
    // If current node is a leaf node
    if( (root->left == NULL) && (root->right == NULL) ){
        delete root;
        return NULL;
    }
    
    // 3. Recursive Case
    // Give updated root of left and right sub-trees of current node.
    else{
        root->left = removeLeafNodes(root->left);
        root->right = removeLeafNodes(root->right);
    }

    return root;
}


int main(){

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    removeLeafNodes(root_node);
    print_level_wise_BT(root_node);

    return 0;
}