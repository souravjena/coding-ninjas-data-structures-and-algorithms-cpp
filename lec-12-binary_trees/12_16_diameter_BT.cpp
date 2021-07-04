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


int diameter_BT(BinaryTreeNode<int>* root){

    // 1. Base Case
    if(root == NULL){
        return 0;
    }

    // 2. Current Problem
    int option1 = height_BT(root->left) + height_BT(root->right);

    // 3. Recursion Case
    int option2 = diameter_BT(root->left);
    int option3 = diameter_BT(root->right);
    
    return max(option1, max(option2, option3));
}


int main(){

    // 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    cout << diameter_BT(root_node) << endl;

    return 0;
}