#include <iostream>
#include <queue>
#include "BinaryTreeNodeFn.h"
using namespace std;

/**
 * @brief [#important, #BT, #recursion] Compute Height and Diameter of a BT in O(n) Time Complexity.
 * 
 * @param root Address of root node of the BT.
 * @return pair<int, int> Height and Diameter of BT in pair class.
 */
pair<int, int> height_diameter_BT(BinaryTreeNode<int>* root){

    int left_ht, left_dia, right_ht, right_dia;
    int curr_ht, curr_dia;
    pair<int, int> ans_left;
    pair<int, int> ans_right;
    pair<int, int> p;
    // p.first = height;
    // p.second = diameter;

    // 1. Base Case
    if(root == NULL){
        p.first = 0;
        p.second = 0;

        return p;
    }


    // 2. Recursive Case
    ans_left = height_diameter_BT(root->left);
    ans_right = height_diameter_BT(root->right);

    left_ht = ans_left.first;
    left_dia = ans_left.second;

    right_ht = ans_right.first;
    right_dia = ans_right.second;


    // 3. Current Problem
    curr_ht = 1 + max(left_ht, right_ht);
    curr_dia = max( (left_ht + right_ht), max(left_dia, right_dia) );

    p.first = curr_ht;
    p.second = curr_dia;

    return p;
}


int main(){

    // 1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    pair<int, int> ans = height_diameter_BT(root_node);
    cout << "height: " << ans.first << endl;
    cout << "diameter: " << ans.second << endl;

    return 0;
}