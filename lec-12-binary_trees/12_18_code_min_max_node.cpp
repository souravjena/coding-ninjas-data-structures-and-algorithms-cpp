#include <iostream>
#include <queue>
#include "BinaryTreeNodeFn.h"
#include <climits>
using namespace std;


pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
    
    pair<int, int> ans, ans_left, ans_right;
    int curr_min, curr_max;

    
    // 1. Base Case
    if(root == NULL){
        ans.first = INT_MAX;        // min
        ans.second = INT_MIN;       // max

        return ans;
    }


    // 2. Recursive Case
    ans_left = getMinAndMax(root->left);
    ans_right = getMinAndMax(root->right);


    // 3. Current Problem
    curr_min = min( root->data, min(ans_left.first, ans_right.first) );
    curr_max = max( root->data, max(ans_left.second, ans_right.second) );

    ans.first = curr_min;
    ans.second = curr_max;

    return ans;
}


int main(){

    // 1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    pair<int, int> ans = getMinAndMax(root_node);
    cout << "min: " << ans.first << endl;
    cout << "max: " << ans.second << endl;

    return 0;
}