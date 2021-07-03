#include <iostream>
#include <queue>
#include "BinaryTreeNodeFn.h"
using namespace std;

/**
 * @brief Construct a BT using postOrder and inOrder array of nodes.
 * 
 * @param preorder Array containing data of nodes of BT in post-order.
 * @param preLength Array Length
 * @param inorder  Array containing data of nodes of BT in in-order.
 * @param inLength Array Length
 * @return BinaryTreeNode<int>* Address of the root of of the Constructed BT. 
 */
BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    
    BinaryTreeNode<int>* root_node = new BinaryTreeNode<int>(0);

    // 1. Base Case
    if(postLength == 1){
        root_node->data = postorder[0];
        return root_node;
    } // Leaf Node is encountered
    else if (postLength == 0){
        return NULL;
    }

    // 2. Current Problem
    root_node->data = postorder[postLength - 1];


    // 3. Recursive Case
    int* left_postorder = postorder;
    int* left_inorder = inorder;
    int left_len = 0;
    
    int* right_postorder;
    int* right_inorder;
    int right_len = 0;

    // NOTE: This will work because we are assuming that all the nodes in the BT are unique.
    for(int i = 0; i < inLength; i++){
        
        if(root_node->data == inorder[i]){
            left_len = i;
            break;
        }
    }

    right_postorder = postorder + left_len;
    right_inorder = inorder + left_len + 1;
    right_len = inLength - left_len - 1;

    root_node->left = buildTree(left_postorder, left_len, left_inorder, left_len);
    root_node->right = buildTree(right_postorder, right_len, right_inorder, right_len);

    return root_node;
}


int main(){

    int len = 7;

    int arr_postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int arr_inorder[] = {4, 2, 5, 1, 6, 3, 7};

    BinaryTreeNode<int>* root_node = buildTree(arr_postorder, len, arr_inorder, len);
    print_level_wise_BT(root_node);

    return 0;
}