#include <iostream>
#include <queue>
#include "BinaryTreeNodeFn.h"
using namespace std;

void postOrder(BinaryTreeNode<int> *root) {
    
    // 1. Base Case
    if(root == NULL){
        return;
    }

    // 2. Recursive Case
    postOrder(root->left);
    postOrder(root->right);

    
    // 3. Current Problem
    cout << root->data << " ";
}


int main(){

    // 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    postOrder(root_node);
    cout << endl;

    return 0;
}