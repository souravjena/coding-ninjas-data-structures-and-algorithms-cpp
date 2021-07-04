#include <iostream>
#include <queue>
#include "BinaryTreeNodeFn.h"
using namespace std;


int getSum(BinaryTreeNode<int>* root) {
    
    int sum;

    // 1. Base Case
    if(root == NULL){
        return 0;
    }

    // 2. Current Prob
    sum = root->data;


    // 3. Recursive Case
    sum += getSum(root->left) + getSum(root->right);


    return sum;
}


int main(){

    // 1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    cout << "sum: " << getSum(root_node) << endl;

    return 0;
}