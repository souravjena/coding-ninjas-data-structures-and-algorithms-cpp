#include <iostream>
// #include "TreeNode.h"
#include "TreeNodeFn.h"
#include <climits>

/**
 * @brief To hold a Tree Node and its sum.
 * 
 */
class Pair{
    public:
        TreeNode<int>* node;
        int sum;

    Pair(){
        this->node = NULL;
        this->sum = INT_MIN;
    }
};


/**
 * @brief Helper function to return max-sum and max-node of a tree.
 * 
 * @param root Address of the root node of the tree.
 * @return Pair Class to hold max-node and max-sum of a tree.
 */
Pair helper_maxSumNode(TreeNode<int>* root){

    Pair max;

    if(root == NULL){
        return max;
    }

    // 1. Compute current node's sum
    int curr_sum = root->data;

    for(int i = 0; i < root->children.size(); i++){
        curr_sum += root->children.at(i)->data;
    }

    max.node = root;
    max.sum = curr_sum;

    // 2. Compute child nodes' sum and compare with current node's sum
    for(int j = 0; j < root->children.size(); j++){
        Pair child = helper_maxSumNode(root->children.at(j));

        if(child.sum > max.sum){
            max.node = child.node;
            max.sum = child.sum;
        } 
    }

    return max;
}

/**
 * @brief Function to just return the max-node as per the requirement of the assignment.
 * 
 * @param root 
 * @return TreeNode<int>* 
 */
TreeNode<int>* maxSumNode_justHelper(TreeNode<int>* root) {

    return(helper_maxSumNode(root).node);

}


TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    Pair max;
    Pair ans;

    if(root == NULL){
        return max.node;
    }

    // 1. Compute current node's sum
    int curr_sum = root->data;

    for(int i = 0; i < root->children.size(); i++){
        curr_sum += root->children.at(i)->data;
    }

    max.node = root;
    max.sum = curr_sum;

    for(int j = 0; j < root->children.size(); j++){

        Pair child = helper_maxSumNode(root->children.at(j));

        if(child.sum > max.sum){
            max.node = child.node;
            max.sum = child.sum;

        } 
    }

    return (max.node);
}



int main(){

    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    // 5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0

    TreeNode<int>* root_node = takeInputLevelWise();
    cout << endl << endl;
    
    printLevelWise(root_node);
    cout << endl << endl;

    cout << maxSumNode_justHelper(root_node)->data << endl;

    return 0;
}