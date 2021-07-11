#include <iostream>
#include <climits>
#include "BinaryTreeNodeFn.h"
using namespace std;

int helper_replaceWithLargerNodesSum(BinaryTreeNode<int> *root, int sum_greater){

    // 1. Base Case
    if(root == NULL){
        return 0;
    }


    // 2. Current & Recursive Case
    int ans_right = helper_replaceWithLargerNodesSum(root->right, sum_greater);

    /* [#important]
        - If sum_greater is larger then it will already have ans_right in it.
        - Therefore no need to add it again.
    */
    if(sum_greater > ans_right){
        root->data += sum_greater;
    } else {
        root->data += ans_right;
    }
    

    int ans_left = helper_replaceWithLargerNodesSum(root->left, root->data);

    /*
        - ans_left will have (left_child_node + root_node). So that can be returend.
        - But if left_child_node is absent then in that case we need to return root->data.
    */
    return max(root->data, ans_left);
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    helper_replaceWithLargerNodesSum(root, 0);
}


int main(){
    
    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    replaceWithLargerNodesSum(root_node);
    print_level_wise_BT(root_node);

    return 0;
}