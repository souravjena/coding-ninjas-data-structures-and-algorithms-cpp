#include <iostream>
// #include "TreeNode.h"
#include "TreeNodeFn.h"


bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {

    // Since we are going to use && we don't want to (ans && something) to be false always
    // as the first boolean will be false if ans is false at the beginning.
    bool ans = true;    

    // Edge Case
    if(root1 == NULL || root2 == NULL){
        return false;
    }

    // Base Case
    // No need to explicity write the base case.

    // Current Problem
    if((root1->children.size()) != (root2->children.size())){
        return false;
    
    } else {

        if((root1->data) == (root2->data)){
            
            // Recursive Case
            for(int i = 0; i < root1->children.size(); i++){
                ans = ans && areIdentical(root1->children.at(i), root2->children.at(i));

                // If any one child is not identical then we can break no need to check further.
                if(ans == false){
                    break;
                }
            }    

        } else {
            return false;
        }

    }

    return ans;
}


int main(){

    /*  Test Input #1
        10 3 20 30 40 2 40 50 0 0 0 0 
        10 3 20 30 40 2 40 50 0 0 0 0
    */

    /*  Test Input #2
        10 3 20 30 40 2 40 50 0 0 0 0 
        10 3 2 30 40 2 40 50 0 0 0 0
    */

    TreeNode<int>* root_node1 = takeInputLevelWise();
    cout << endl << endl;
    
    printLevelWise(root_node1);
    cout << endl << endl;

    TreeNode<int>* root_node2 = takeInputLevelWise();
    cout << endl << endl;
    
    printLevelWise(root_node2);
    cout << endl << endl;

    cout << areIdentical(root_node1, root_node2) << endl;
}