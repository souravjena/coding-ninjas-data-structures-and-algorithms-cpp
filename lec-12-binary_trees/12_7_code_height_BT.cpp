#include <iostream>
#include <queue>
#include "BinaryTreeNodeFn.h"
using namespace std;

/**
 * @brief [#BT, #recursion] [12.7 C] Find height of a BT.
 * 
 * @param root Address of the root node of the BT.
 * @return int Height of the BT.
 */
int height(BinaryTreeNode<int>* root) {
    
    // 1. Base Case
    if(root == NULL){
        return 0;
    }
    
    // 2. Recursive Case
    int left_ht = height(root->left);
    int right_ht = height(root->right);

    // 3. Current Problem
    if(left_ht >= right_ht){
        return (1 + left_ht);
    } else {
        return (1 + right_ht);
    }
}

int main(){

    // 10 20 30 40 50 -1 -1 -1 -1 -1 -1

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    cout << "Height: " << height(root_node) << endl;

    return 0;
}