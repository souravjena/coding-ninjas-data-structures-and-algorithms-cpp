#include <iostream>
#include <queue>
#include "BinaryTreeNodeFn.h"
using namespace std;

/**
 * @brief Check if a node is present in the BT or not.
 * 
 * @param root Address of the root node of the BT.
 * @param x Data whose presence in the BT will be checked.
 * @return true If the node is present.
 * @return false If the node is not present.
 */
bool isNodePresent(BinaryTreeNode<int> *root, int x) {

    bool curr = true;

    // Base
    if(root == NULL){
        return false;
    }

    // Current
    if(root->data == x){
        return true;
    } else {
        curr = false;
    }

    // Recursive
    return (curr || isNodePresent(root->left, x) || isNodePresent(root->right, x));
}



int main(){

    // 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
    // 7

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    cout << isNodePresent(root_node, 7) << endl;

    return 0;
}