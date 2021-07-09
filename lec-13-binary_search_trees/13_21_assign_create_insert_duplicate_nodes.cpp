#include <iostream>
#include "BinaryTreeNodeFn.h"
using namespace std;


void insertDuplicateNode(BinaryTreeNode<int> *root) {

    // 1. Base Case
    if(root == NULL){
        return;
    }

    // 2. Current Problem
    BinaryTreeNode<int>* duplicate_node = new BinaryTreeNode<int>(root->data);

    duplicate_node->left = root->left;
    root->left = duplicate_node;

    // 3. Recursive Case
    insertDuplicateNode(duplicate_node->left);
    insertDuplicateNode(root->right);

}


int main(){
    
    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    insertDuplicateNode(root_node);
    print_level_wise_BT(root_node);

    return 0;
}