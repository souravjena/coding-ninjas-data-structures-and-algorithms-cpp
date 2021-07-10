#include <iostream>
#include <climits>
#include "BinaryTreeNodeFn.h"
using namespace std;


/*
    ** Approach #1 ** 
    - Time Complexity: O(n^2)
    - Space Complexity: O(1)
*/

/*
    1. Assume the given binary tree contains all unique elements.
    2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
*/

bool find_and_replace(BinaryTreeNode<int> *root, int x, int replace) {

    bool curr = true;
    
    // Base
    if(root == NULL){
        return false;
    }

    // Current
    if(root->data == x){
        root->data = replace;
        return true;
    } else {
        curr = false;
    }

    // Recursive
    return (curr || find_and_replace(root->left, x, INT_MIN) || find_and_replace(root->right, x, INT_MIN));
}

void helper_pairSum(BinaryTreeNode<int> *node, int sum, BinaryTreeNode<int> *root) {
    
    // 1. Base Case
    if(node == NULL){
        return;
    }

    // 2. Current Problem
    int remaining = sum - node->data;
    

    if ( (find_and_replace(root, remaining, INT_MIN) == true) && (node->data != INT_MIN) ){
        if(remaining < node->data){
            cout << remaining << " " << node->data << endl;
        } else {
            cout << node->data << " " << remaining << endl;
        }
    }

    // 3. Recursive Case
    helper_pairSum(node->left, sum, root);
    helper_pairSum(node->right, sum, root);
    
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    helper_pairSum(root, sum, root);    
}


int main(){
    
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    // 8

    int sum = 8;
    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    pairSum(root_node, sum);

    return 0;
}