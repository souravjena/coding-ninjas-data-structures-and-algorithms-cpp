#include <iostream>
#include <climits>
#include "BinaryTreeNodeFn.h"
using namespace std;

int min_bst(BinaryTreeNode<int>* root){

    // 1. Base Case
    if(root == NULL){
        return INT_MAX;
    }

    // 2. Recursive Case
    int ans_left = min_bst(root->left);
    int ans_right = min_bst(root->right);

    // 3. Current Problem
    int ans_curr = min(root->data, min(ans_left, ans_right));

    return ans_curr;
}


int max_bst(BinaryTreeNode<int>* root){

    // 1. Base Case
    if(root == NULL){
        return INT_MIN;
    }

    // 2. Recursive Case
    int ans_left = max_bst(root->left);
    int ans_right = max_bst(root->right);

    // 3. Current Problem
    int ans_curr = max(root->data, max(ans_left, ans_right));

    return ans_curr;
}


/**
 * @brief   [#important, #recursion, #BST]
 *          [13.7 Lec Check BST-1] 
 *          Top-to-Bottom approach to find if a BT is a BST or not.
 *          Multiple Recursive Calls per node.
 *          O(nh) complexity. h = height of BT. h = log2(n) if tree is balanced. h = n is tree is linear.
 * 
 * @param root Address of the root node of the BT.
 * @return true If the BT is a BST.
 * @return false If the BT is not a BST.
 */
bool isBST(BinaryTreeNode<int> *root) {

    // 1. Base Case
    if(root == NULL){
        return true;
    }


    // 2. Recursive Case
    bool ans_left = isBST(root->left);
    bool ans_right = isBST(root->right);


    // 3. Current Problem
    int max_left = max_bst(root->left);
    int min_right = min_bst(root->right);
    bool ans_curr = (max_left < root->data) && (root->data <= min_right);


    return (ans_curr && ans_left && ans_right);
}


int main(){

    // 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
 
    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;
    
    cout << "Is BST? : " << isBST(root_node) << endl;

    return 0;
}