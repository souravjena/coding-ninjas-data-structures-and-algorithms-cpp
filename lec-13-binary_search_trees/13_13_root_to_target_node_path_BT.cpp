#include <iostream>
#include <vector>
#include "BinaryTreeNodeFn.h"
using namespace std;


vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data) {

    vector<int>* vec_curr = NULL;
    vector<int>* vec_left = NULL;
    vector<int>* vec_right = NULL;
    
    // 1. Base Case
    if(root == NULL){
        return NULL;
    }

    // 2. Current/Base
    if(root->data == data){
        vec_curr = new vector<int>();
        vec_curr->push_back(root->data);
        return vec_curr;
    }

    // 3. Recursive Case
    
    // 3.1 First look at left sub-tree
    /*
    - If the target node is present then add current data to the vector returned
        by the left sub-tree.
    - Return this vector.
    - Else look at the right sub-tree.
    - If the node is present in the right sub-tree then add and return.
    - Else it means the traget node is not present in the BT so return NULL.
    */ 

    vec_left = getRootToNodePath(root->left, data);

    if(vec_left != NULL){
        vec_left->push_back(root->data);
        return vec_left;
    }

    
    vec_right = getRootToNodePath(root->right, data);

    if(vec_right != NULL){
        vec_right->push_back(root->data);
        return vec_right;
    } else {
        return NULL;
    }
    
}


int main() {
    
    BinaryTreeNode<int>* root = NULL;
    int target = 8;

    root = input_level_wise_BT();
    vector<int>* ans = getRootToNodePath(root, target);

    cout << endl << "________________" << endl;

    for(int i = 0; i < ans->size(); i++){
        cout << ans->at(i) << " ";
    }
    cout << endl;

    return 0;
}