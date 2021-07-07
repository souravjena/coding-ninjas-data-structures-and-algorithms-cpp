#include <iostream>
#include "BinaryTreeNodeFn.h"
using namespace std;

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
    
    // 1. Base Case
    if(root == NULL){
        return;
    }

    // 2. Current Problem and
    // 3. Recursive Case
    if( (root->data >= k1) && (root->data <= k2) ){

        // Print in ascending order
        elementsInRangeK1K2(root->left, k1, k2);
        cout << root->data << " ";
        elementsInRangeK1K2(root->right, k1, k2);
    
    } else if (root->data < k1){
        elementsInRangeK1K2(root->right, k1, k2);
    } else {
        elementsInRangeK1K2(root->left, k1, k2);
    }
}

int main(){

    // 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    // 6 10

    int k = 12;

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;
    
    elementsInRangeK1K2(root_node, 6, 10);

    return 0;
}