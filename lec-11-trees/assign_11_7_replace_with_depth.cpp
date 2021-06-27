#include <iostream>
#include "TreeNodeFn.h"
using namespace std;

/**
 * @brief Helper function to replace Data value with Depth
 * 
 * @param root Address of the root node of the tree.
 * @param arg_level Level or Depth of the root in the tree.
 */
void helper_replaceWithDepthValue(TreeNode<int>* root, int arg_level) {
    
    int num_child;

    // Edge Case
    if(root == NULL){
        return;
    }

    num_child = root->children.size();
    
    // 1. Base Case
    if(num_child == 0){
        root->data = arg_level;
        return;
    }

    // 2. Current Problem
    root->data = arg_level;

    // 3. Recursive Case
    for(int i = 0; i < num_child; i++){
        helper_replaceWithDepthValue(root->children.at(i), arg_level + 1);
    }

}

/**
 * @brief Original Function for the assignment.
 * 
 * @param root Address of the root node of the tree.
 */
void replaceWithDepthValue(TreeNode<int>* root) {
    helper_replaceWithDepthValue(root, 0);
}


int main(){

    // 10 3 20 30 40 2 40 50 0 0 0 0 

    TreeNode<int>* root_node = takeInputLevelWise();
    cout << endl << endl;
    
    printLevelWise(root_node);
    cout << endl << endl;

    replaceWithDepthValue(root_node);
    
    printLevelWise(root_node);
    cout << endl << endl;

}