#include <iostream>
// #include "TreeNode.h"
#include "TreeNodeFn.h"
#include <climits>

class Pair{
    public:
        TreeNode<int>* node;
        int sum;

    Pair(){
        this->node = NULL;
        this->sum = INT_MIN;
    }
};

Pair helper_maxSumNode(TreeNode<int>* root){

    Pair ans;

    if(root == NULL){
        return ans;
    }

    // 1. Compute current node's sum
    int curr_sum = root->data;
    // cout << "root->data = " << root->data << endl;
    

    if(root->children.size() != 0){
        
        for(int i = 0; i < root->children.size(); i++){
            curr_sum += root->children.at(i)->data;
            // cout << "child_sum = " << curr_sum << endl;
        }

        // 2. Compute child nodes' sum and compare with current node's sum
        for(int j = 0; j < root->children.size(); j++){
            // cout << "loop: " << root->children.at(j)->data << endl;

            Pair child = helper_maxSumNode(root->children.at(j));

            // cout << "curr sum = " << curr_sum << "\t child sum = " << child.sum << endl;

            if(child.sum > curr_sum){
                ans.node = child.node;
                ans.sum = child.sum;
                // cout << "if" << endl;

            } else {
                ans.node = root;
                ans.sum = curr_sum;
                // cout << "else" << endl;
            }
        }
    
    } else {
        if(curr_sum > ans.sum){
            ans.node = root;
            ans.sum = curr_sum;
        }
    }

    cout << "ans sum = " << ans.sum << endl << endl;

    return ans;
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

    cout << maxSumNode(root_node)->data << endl;

    return 0;
}