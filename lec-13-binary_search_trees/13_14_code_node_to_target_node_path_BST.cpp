#include <iostream>
#include <vector>
#include "BinaryTreeNodeFn.h"
using namespace std;


vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
    
    // 1. Base Case
    if(root == NULL){
        return NULL;
    }


    // 2. Current Case
    if(root->data == data){
        vector<int>* ans = new vector<int>();
        ans->push_back(root->data);
        return ans;
    }


    // 3. Recursive Case
    if(data < root->data){
        // Go left
        vector<int>* ans_left = getPath(root->left, data);

        if(ans_left != NULL){
            ans_left->push_back(root->data);
            return ans_left;
        }

    } else {
        // Go right
        vector<int>* ans_right = getPath(root->right, data);

        if(ans_right != NULL){
            ans_right->push_back(root->data);
            return ans_right;
        } else {
            return NULL;
        }
    }
}


int main() {
    
    BinaryTreeNode<int>* root = NULL;
    int target = 2;

    root = input_level_wise_BT();
    vector<int>* ans = getPath(root, target);

    cout << endl << "________________" << endl;

    for(int i = 0; i < ans->size(); i++){
        cout << ans->at(i) << " ";
    }
    cout << endl;

    return 0;
}