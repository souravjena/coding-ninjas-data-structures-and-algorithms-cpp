#include <iostream>
// #include "TreeNode.h"
#include "TreeNodeFn.h"

/**
 * @brief Get the number of nodes greater than x in the tree.
 * 
 * @param root Address of the root node of the tree.
 * @param x Data that we need to compare.
 * @return int Count of number of nodes greater than x in the tree.
 */
int getLargeNodeCount(TreeNode<int>* root, int x) {

    int count = 0;

    // Edge Case
    if(root == NULL){
        return 0;
    }

    // 1. Base Case
    // If the current node is a leaf node
    // and if (root->data < x) then (count = 0) will be returned.

    // 2. Current Problem
    if(root->data > x){
        count++;      // Count itself
    }

    // 3. Recursive Case
    for(int i = 0; i < root->children.size(); i++){
        count += getLargeNodeCount(root->children.at(i), x);
    }

    return count;
}


int main(){

    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

    TreeNode<int>* root_node = takeInputLevelWise();
    cout << endl << endl;
    
    printLevelWise(root_node);
    cout << endl << endl;

    cout << "# Larger Nodes: " << getLargeNodeCount(root_node, 1) << endl;

    return 0;
}