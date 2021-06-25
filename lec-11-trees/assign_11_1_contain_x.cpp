#include <iostream>
// #include "TreeNode.h"
#include "TreeNodeFn.h"

/**
 * @brief [#trees, #recursion] To check if a node is present in the tree or not.
 * 
 * @param root Address of the root node of the tree.
 * @param x    Data to be checked in the tree.
 * @return true If the data is present.
 * @return false If the data is not present in the tree.
 */
bool isPresent(TreeNode<int>* root, int x) {

    bool ans = false;

    // Edge Case
    if(root == NULL){
        return false;
    }

    // 1. Base Case
    if(root->data == x){
        return true;
    }

    // Recursive Case and Current Problem
    for(int i = 0; i < root->children.size(); i++){
        ans = ans || isPresent( root->children.at(i), x); 
    }

    return ans;
}


int main(){

    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

    TreeNode<int>* root_node = takeInputLevelWise();
    cout << endl << endl;
    printLevelWise(root_node);
    cout << endl << endl;

    cout << isPresent(root_node, 9);
    cout << endl;

    return 0;
}