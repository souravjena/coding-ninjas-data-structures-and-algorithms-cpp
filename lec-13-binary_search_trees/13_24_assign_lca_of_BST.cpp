#include <iostream>
#include "BinaryTreeNodeFn.h"
using namespace std;

int getLCA(BinaryTreeNode <int>* root , int val1 , int val2) {
    
    // 1. Base Case
    if(root == NULL){
        return -1;
    }

    if( (root->data == val1) || (root->data == val2) ){
        return root->data;
    }

    if( (val1 < root->data) && (val2 > root->data) ){
        return root->data;
    }
    
    // 2. Recursive Case
    if( (root->data < val1) && (root->data < val2) ){
        return getLCA(root->right, val1, val2);
    } else {
        return getLCA(root->left, val1, val2);
    }
}

int main(){
    
    // 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    int n1 = 14;
    int n2 = 15;

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    cout << getLCA(root_node, n1, n2) << endl;

    return 0;
}