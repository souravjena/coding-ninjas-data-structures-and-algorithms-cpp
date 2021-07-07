#include <iostream>
#include <climits>
#include "BinaryTreeNodeFn.h"
using namespace std;


class isBSTReturn {
    public:
        bool isBST;
        int max;
        int min;
};

/**
 * @brief   [#important, #recursion, #BST]
 *          [13.8 Lec Check BST-2] 
 *          Top-to-Bottom approach to find if a BT is a BST or not. 
 *          Single Recursive Call per node.
 *          O(h) complexity. n = # of nodes.
 * 
 * @param root Address of the root node of the BT.
 * @return isBSTReturn If the BT is a BST.
 */
isBSTReturn helper_isBST(BinaryTreeNode<int>* root){

    isBSTReturn ans_curr, ans_left, ans_right;

    // 1. Base Case
    if(root == NULL){
        ans_curr.isBST = true;
        ans_curr.max = INT_MIN;
        ans_curr.min = INT_MAX;

        return ans_curr;
    }


    // 2. Recursive Case
    ans_left = helper_isBST(root->left);
    ans_right = helper_isBST(root->right);


    // 3. Current Problem
    ans_curr.isBST = (ans_left.max < root->data) && (root->data <= ans_right.min) && ans_left.isBST && ans_right.isBST;
    ans_curr.max = max(root->data, max(ans_left.max, ans_right.max));
    ans_curr.min = min(root->data, min(ans_left.min, ans_right.min));

    return ans_curr;
}


bool isBST(BinaryTreeNode<int> *root) {
    return (helper_isBST(root).isBST);
}


int main(){

    // 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    // 6 10

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;
    
    cout << "Is BST? : " << isBST(root_node) << endl;

    return 0;
}