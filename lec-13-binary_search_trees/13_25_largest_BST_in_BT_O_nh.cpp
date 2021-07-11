#include <iostream>
#include <climits>
#include "BinaryTreeNodeFn.h"
using namespace std;

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


int height_bt(BinaryTreeNode<int> *root){

    // 1, Base Case
    if(root == NULL){
        return 0;
    }

    // 2. Current
    // Leaf Node encountered
    if( (root->left == NULL) && (root->right == NULL) ){
        return 1;
    }

    // 3. Recursive Case
    int ans_left = height_bt(root->left);
    int ans_right = height_bt(root->right);

    return max(ans_left + 1, ans_right + 1);
}


int largestBSTSubtree(BinaryTreeNode<int> *root) {
    
    // 1. Base Case
    if(root == NULL){
        return 0;
    }

    // 2. Current
    if( isBST(root) == true ){
        cout << ">> " << root->data << endl;
        return height_bt(root);
    
    } 
    
    // 3. Recursive
    int ans_left = largestBSTSubtree(root->left);
    int ans_right = largestBSTSubtree(root->right);

    return max(ans_left, ans_right);
}


int main(){
    
    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    cout << largestBSTSubtree(root_node) << endl;
    cout << height_bt(root_node) << endl;

    return 0;
}