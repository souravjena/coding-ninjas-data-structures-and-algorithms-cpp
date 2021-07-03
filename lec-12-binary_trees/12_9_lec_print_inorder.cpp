#include <iostream>
#include <queue>
#include "BinaryTreeNodeFn.h"
using namespace std;

/**
 * @brief [#BT, #recursion][12.9 L] Inorder printing of BT.
 * 
 * @param root Address of the root node of the BT.
 */
void print_inorder_BT(BinaryTreeNode<int>* root) {
    
    // Base Case
    if(root == NULL){
        return;
    }

    // Recursive Case & Current Problem
    print_inorder_BT(root->left);
    cout << root->data << " ";
    print_inorder_BT(root->right);
}


int main(){

    // 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    print_inorder_BT(root_node);
    cout << endl;

    return 0;
}