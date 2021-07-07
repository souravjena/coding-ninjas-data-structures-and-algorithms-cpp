#include <iostream>
#include <climits>
#include "BinaryTreeNodeFn.h"
using namespace std;


/**
 * @brief   [#important, #recursion, #BST]
 *          [13.9 Lec Check BST-3] 
 *          Top-to-Bottom approach to find if a BT is a BST or not. 
 *          O(n) complexity.
 * 
 * @param root Address of the root node of the BT.
 * @param min  Minimum value of the root data for the BT to be a BST.
 * @param max  Maximum value of the root data for the BT to be a BST.
 * @return true If the BT is a BST.
 * @return false If the BT is not a BST.
 */
bool helper_isBST(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX){

    // 1. Base Case
    if(root == NULL){
        return true;
    }

    
    // 2. Current Problem
    // If root data is not in valid range then return false.
    if( (root->data <= min) || (root->data > max) ){
        return false;
    }

    
    // 3. Recursive Case
    bool ans_left_subtree = helper_isBST(root->left, min, (root->data - 1) );
    bool ans_right_subtree = helper_isBST(root->right, root->data, max);


    return (ans_left_subtree && ans_right_subtree);
}


bool isBST(BinaryTreeNode<int> *root) {

    return helper_isBST(root);

}

/*

// This approach is incorrect because we are just checking if a left and right subtrees are a BST or not.
// But a subtree though a BST may have an element which can be greater than the root itself then in that case
// the BT should not be considered as a BST.

bool isBST(BinaryTreeNode<int> *root) {
	
    bool ans;

    // 1. Base Case
    if(root == NULL){
        return true;
    }

    // 2. Current Problem
    if( (root->left != NULL) || (root->right != NULL) ){
        
        if((root->left != NULL) && (root->left->data > root->data) ){
            return false;
        }

        if( (root->right != NULL) && (root->data > root->right->data) ){
            return false;
        }
    }
    
    // 3. Recursive Case
    ans = isBST(root->left) && isBST(root->right);

    return ans;
}
*/


int main(){

    // 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    // 6 10

    int k = 12;

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;
    
    cout << "Is BST? : " << isBST(root_node) << endl;

    return 0;
}