#include <iostream>
#include <queue>
#include "BinaryTreeNodeFn.h"
using namespace std;

void preOrder(BinaryTreeNode<int> *root) {
    
    // 1. Base Case
    if(root == NULL){
        return;
    }

    // 2. Current Problem
    cout << root->data << " ";

    // 3. Recursive Case
    preOrder(root->left);
    preOrder(root->right);
}


int main(){

    // 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    preOrder(root_node);
    cout << endl;

    return 0;
}