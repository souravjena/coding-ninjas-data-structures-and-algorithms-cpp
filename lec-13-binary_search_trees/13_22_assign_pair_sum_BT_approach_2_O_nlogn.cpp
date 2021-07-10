#include <iostream>
#include <climits>
#include <algorithm>    // std::sort
#include <vector>
#include "BinaryTreeNodeFn.h"
using namespace std;


/*
    ** Approach #2 ** 
    - Time Complexity: O(nlogn)
    - Space Complexity: O(n)
*/

/*
    1. Assume the given binary tree contains all unique elements.
    2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
*/

vector<int>* bst_to_vec(BinaryTreeNode<int> *root){

    vector<int>* v = new vector<int>();

    // 1. Base Case
    if(root == NULL){
        return NULL;
    }

    // 2. Current Problem
    v->push_back(root->data);

    // 3. Recursive Case
    vector<int> *v_left = bst_to_vec(root->left);
    vector<int> *v_right = bst_to_vec(root->right);

    // [#important] Merge v_left, v_right with v
    if(v_left != NULL){
        v->insert(v->end(), v_left->begin(), v_left->end());
    }
    
    if(v_right != NULL){
        v->insert(v->end(), v_right->begin(), v_right->end());
    }
    
    return v;
}

void pairSum(BinaryTreeNode<int> *root, int sum) {

    // 1. BST to Vector
    vector<int> *v = bst_to_vec(root);

    // 2. Sort the Vector
    sort(v->begin(), v->end());

    // 3. Iterate over the Vector and find Pairs
    int i = 0;
    int j = v->size() - 1;

    while(i < j){

        int x = v->at(i);
        int y = v->at(j); 
        
        if(x + y == sum){
            cout << x << " " << y << endl;
            i++;
            j--;
        
        } else if(x + y < sum){
            i++;
        } else {
            j--;
        }
    }
}


int main(){
    
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    // 8

    int sum = 15;
    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    pairSum(root_node, sum);
    // bst_to_vec(root_node);

    return 0;
}