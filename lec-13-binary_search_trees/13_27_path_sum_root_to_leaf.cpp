#include <iostream>
#include <vector>
#include "BinaryTreeNodeFn.h"
using namespace std;

void helper_rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int sum_remaining, vector<int> path){

    // 1. Base Case
    if(root == NULL){
        return;
    }

    // 2. Current
    // Leaf node encountered
    if(root->left == NULL && root->right == NULL){

        if(sum_remaining == root->data){
            
            for(int i = 0; i < path.size(); i++){
                cout << path.at(i) << " ";
            }
            
            cout << root->data << endl;
        
        } else {
            return;
        }
    
    } else {

        // 3. Recursive Case
        path.push_back(root->data);

        helper_rootToLeafPathsSumToK(root->left, sum_remaining - root->data, path);
        helper_rootToLeafPathsSumToK(root->right, sum_remaining - root->data, path);

    }
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    
    vector<int> path;

    helper_rootToLeafPathsSumToK(root, k, path);
}

int main(){
    
    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    rootToLeafPathsSumToK(root_node, 13);

    return 0;
}