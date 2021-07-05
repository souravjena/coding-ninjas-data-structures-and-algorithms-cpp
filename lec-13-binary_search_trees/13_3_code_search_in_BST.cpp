#include <iostream>
#include "BinaryTreeNodeFn.h"
using namespace std;

bool searchInBST(BinaryTreeNode<int> *root , int k) {
	
    bool ans = false;

    // 1. Base Case
    if(root == NULL){
        return false;
    }


    // 2. Current Problem
    if(root->data == k){
        return true;
    }

    // 3. Recursive Case
    if(k < root->data){
        ans = ans || searchInBST(root->left, k);
    } else {
        ans = ans || searchInBST(root->right, k);
    }

}

int main(){

    // 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    // 2

    int k = 12;

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;
    
    cout << searchInBST(root_node, k) << endl;

    return 0;
}