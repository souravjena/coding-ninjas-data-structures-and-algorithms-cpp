#include <iostream>
#include <queue>
#include "BinaryTreeNodeFn.h"
using namespace std;

int height_BT(BinaryTreeNode<int>* root){
    
    int height;

    // 1. Base Case
    if(root == NULL){
        return 0;
    }

    // 2. Current Case
    height = 1;

    // 3. Recursive Case
    height += max(height_BT(root->left), height_BT(root->right));

    return height;
}

bool isBalanced(BinaryTreeNode<int> *root) {
    
    bool ans_left, ans_right;
    int left_ht, right_ht;

    if(root == NULL){
        return true;
    }

    left_ht = height_BT(root->left);
    right_ht = height_BT(root->right);

    if( (left_ht - right_ht > 1) || (right_ht - left_ht > 1) ){
        return false;
    }

    ans_left = isBalanced(root->left);
    ans_right = isBalanced(root->right);

    return (ans_left && ans_right);
}


int main(){

    // 1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    cout << "balanced: " << isBalanced(root_node) << endl;

    return 0;
}