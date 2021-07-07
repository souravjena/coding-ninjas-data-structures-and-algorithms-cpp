#include <iostream>
#include "BinaryTreeNodeFn.h"
using namespace std;


BinaryTreeNode<int>* helper_constructTree(int *input, int start_idx, int end_idx) {
    
    BinaryTreeNode<int>* root = NULL;
    int mid_idx = start_idx + ((end_idx - start_idx)/2);

    cout << start_idx << "\t" << mid_idx << "\t" << end_idx << endl;

    // 1. Base Case
    if( start_idx >= end_idx ){
        root = new BinaryTreeNode<int>(input[start_idx]);
        return root;
    }    

    // 2. Current Problem
    root = new BinaryTreeNode<int>(input[mid_idx]);

    // 3. Recursive Case
    root->left = helper_constructTree(input, start_idx, mid_idx - 1);
    root->right = helper_constructTree(input, mid_idx + 1, end_idx);

    return root;
}


BinaryTreeNode<int>* constructTree(int *input, int n) {
    return(helper_constructTree(input, 0, n - 1));
}


int main(){

    // 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    // 6 10
    BinaryTreeNode<int>* root_node = NULL;

    int arr_sorted[6] = {1, 2, 3, 4, 5, 6};

    root_node = constructTree(arr_sorted, 6);

    print_level_wise_BT(root_node);

    return 0;
}