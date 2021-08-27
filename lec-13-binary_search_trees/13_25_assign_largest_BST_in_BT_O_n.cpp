#include <iostream>
#include <climits>
#include "BinaryTreeNodeFn.h"
using namespace std;

class returnBSTInfo {

    public:
        int min;
        int max;
        int height;
        bool isBST;
};


returnBSTInfo* helper_largestBSTSubtree(BinaryTreeNode<int> *root){

    returnBSTInfo* ans = new returnBSTInfo();

    // 1. Base Case
    if(root == NULL){
        ans->min = INT_MAX;
        ans->max = INT_MIN;
        ans->height = 0;
        ans->isBST = false;

        return ans;
    }

    

    // 2. Recursive Case
    returnBSTInfo* ans_left = helper_largestBSTSubtree(root->left);
    returnBSTInfo* ans_right = helper_largestBSTSubtree(root->right);



    // 3. Current Problem
    if( (ans_left->isBST == true) && (ans_right->isBST == true) ){

        if( (ans_left->max < root->data) && (root->data < ans_right->min) ){
            
            ans->min = ans_left->min;
            ans->max = ans_right->max;
            ans->height = max(ans_left->height, ans_right->height) + 1;
            ans->isBST = true;
            
            return ans;
        
        } else {
            
            if(ans_right->height > ans_left->height){
                return ans_right;
            } else {
                return ans_left;
            }

        }
    
    } else if( (ans_left->isBST == true) && (ans_right->isBST == false) ){

        if( (ans_left->max < root->data) ){

            ans->min = ans_left->min;
            ans->max = root->data;
            ans->height = ans_left->height + 1;
            ans->isBST = true;
            
            return ans;
        
        } else {
            return ans_left;
        }

    } else if( (ans_left->isBST == false) && (ans_right->isBST == true) ){

        if( (root->data < ans_right->min) ){

            ans->min = root->data;
            ans->max = ans_right->max;
            ans->height = ans_right->height + 1;
            ans->isBST = true;
            
            return ans;
        
        } else {
            return ans_right;
        }

    } else if( (ans_left->isBST == false) && (ans_right->isBST == false) ){
            ans->min = root->data;
            ans->max = root->data;
            ans->height = 1;
            ans->isBST = true;

            return ans;      
    }
    
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {

    returnBSTInfo* ans = helper_largestBSTSubtree(root);

    return ans->height;
}


int main(){
    
    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    cout << largestBSTSubtree(root_node) << endl;

    return 0;
}