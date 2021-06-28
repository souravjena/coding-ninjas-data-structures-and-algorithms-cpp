#include <iostream>
#include <queue>
#include "BinaryTreeNodeFn.h"
using namespace std;

/**
 * @brief [#BT, #recursion][12.8 C] Mirror image of a BT.
 * 
 * @param root Address of the root node of the BT.
 */
void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    
    // 1. Base Case
    if(root == NULL){
        return;
    }

    // 2. Current Problem
    // Swap L and R of current node
    BinaryTreeNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // 3. Recursive Case
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

}


int main(){

    // 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    mirrorBinaryTree(root_node);
    print_level_wise_BT(root_node);

    return 0;
}