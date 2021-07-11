#include <iostream>
#include <vector>
#include "BinaryTreeNodeFn.h"
using namespace std;


void print_nodes_at_depth(BinaryTreeNode<int>* root, int depth){

    // 1. Base Case
    if(root == NULL){
        return;
    }

    // 2. Current
    if(depth == 0){
        cout << root->data << endl;
        return;
    }

    // 3. Recursive Case
    print_nodes_at_depth(root->left, depth - 1);
    print_nodes_at_depth(root->right, depth - 1);
}

// [#important]
int helper_nodesAtDistanceK(BinaryTreeNode<int>* root, int target, int depth) {
    
    // 1. Base Case
    if(root == NULL){
        return -1;
    }


    // 2. Current
    if(root->data == target){
        print_nodes_at_depth(root, depth);
        return 0;
    }

    // If root is not target then search left and right sub-trees for target
    int left_dis = helper_nodesAtDistanceK(root->left, target, depth);
    int right_dis = helper_nodesAtDistanceK(root->right, target, depth);

    /*
    - left_dis will hold distance of root of left subtree from target node.

    - If (left_dis + 1) == k that would mean that root is at distance k so then print root->data.

    - If (left_dis + 1) < k that would mean that desirable nodes are on the other side of current root.
        - The nodes which are at distance k from target are on other side of the root so that 
        (left_dis + 1 + x) == k.
        - To print such nodes we can print nodes at depth (k - left_dis - 2) from root of right subtree.

    - If (left_dis + 1 > k) then that would mean that the target node is deeper by (k + (k - (left_dis + 1))
        - So print nodes at depth (k + (k - (left_dis + 1)) from root of left subtree.
        - If the target node is in the left sub tree then we will go deeper and deeper in that tree. So,
          there is no need these node again as because of recursion we are going to encounter them again.
        - Since from left sub tree we can't go to other side therefore we need the previous if-else.
    */

    if(left_dis != -1){

        if( (left_dis + 1) == depth ){
            cout << root->data << endl;
        } else if ( (left_dis + 1) < depth ) {
            print_nodes_at_depth(root->right, (depth - left_dis - 2) );
        } 
        // else {
        //     print_nodes_at_depth(root->left, (depth + (depth - (left_dis + 1))) );
        // }

        return (1 + left_dis);
    }

    if(right_dis != -1){

        if( (right_dis + 1) == depth ){
            cout << root->data << endl;
        } else if ( (right_dis + 1) < depth ) {
            print_nodes_at_depth(root->left, (depth - right_dis - 2) );
        } 
        // else {
        //     print_nodes_at_depth(root->right, (depth + (depth - (right_dis + 1))) );
        // }

        return (1 + right_dis);
    }

    // If target node is not found in left and right subtree then return -1.
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    helper_nodesAtDistanceK(root, node, k);
}

int main(){
    
    // 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
    int target = 3;
    int dis = 1;

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    nodesAtDistanceK(root_node, target, dis);

    return 0;
}