#include <iostream>
#include <queue>
#include <vector>
#include "BinaryTreeNodeFn.h"
using namespace std;


void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    
    // 1. Base Case
    if(root == NULL){
        return;
    }


    // 2. Current Problem
    if( (root->left != NULL) && (root->right == NULL) ){

        cout << root->left->data << " ";
    
    } else if ( (root->right != NULL) && (root->left == NULL) ){

        cout << root->right->data << " ";

    }


    // 3. Recursive Case
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);

    cout << endl;
}


int main(){

    // 2 4 5 6 -1 -1 7 20 30 80 90 -1 -1 -1 -1 -1 -1 -1 -1

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    printNodesWithoutSibling(root_node);

    return 0;
}