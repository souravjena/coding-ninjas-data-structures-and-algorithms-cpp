#include <iostream>
#include "TreeNodeFn.h"
using namespace std;

/**
 * @brief To find the smallest element which is larger than given x in the tree.
 * 
 * @param root Address of the root node of the tree.
 * @param x The number
 * @return TreeNode<int>* Address of the node which is just larger than x. 
 */
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {

    vector<TreeNode<int>*> v;
    int min = INT_MAX;
    int min_index;
    int num_child;

    // Edge Case
    if(root == NULL){
        return NULL;
    }

    num_child = root->children.size();

    // 1. Base Case
    if(num_child == 0){
        
        if(root->data > x){
            return root;
        } else {
            return NULL;
        }
    }

    // 2. Recursive Case
    for(int i = 0; i < num_child; i++){
        TreeNode<int>* largest_child = getNextLargerElement(root->children.at(i), x);

        if(largest_child != NULL){
            v.push_back(largest_child);
        }
    }

    
    // 3. Current Problem
    if(root->data > x){
        v.push_back(root);
    }

    // Return the node in the vector with smallest data
    if(v.empty() == false){
        for(int j = 0; j < v.size(); j++){
        
            TreeNode<int>* curr_node = v.at(j);
            int curr_data = v.at(j)->data; 
            
            if(curr_data < min){
                min = curr_data;
                min_index = j;
            }
        }
        return v.at(min_index);
   
    } else {
        return NULL;
    }
}

int main(){

    // 10 3 20 30 40 2 40 50 0 0 0 0 

    TreeNode<int>* root_node = takeInputLevelWise();
    cout << endl << endl;
    
    printLevelWise(root_node);
    cout << endl << endl;

    cout << getNextLargerElement(root_node, 1)->data << endl;
}