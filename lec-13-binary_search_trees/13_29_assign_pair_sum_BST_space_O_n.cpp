#include <iostream>
#include <vector>
#include "BinaryTreeNodeFn.h"
using namespace std;

vector<int>* bst_to_sorted_vec(BinaryTreeNode<int>* root){

    // ** Inorder traversal of BST gives sorted array. **

    vector<int>* ans = new vector<int>();

    // 1. Base Case
    if(root == NULL){
        return NULL;
    }

    // Inorder: Left->Root->Right
    vector<int>* ans_left = bst_to_sorted_vec(root->left);
    if(ans_left != NULL){
        ans->insert(ans->end(), ans_left->begin(), ans_left->end());
    }
    
    ans->push_back(root->data);

    vector<int>* ans_right = bst_to_sorted_vec(root->right);
    if(ans_right != NULL){
        ans->insert(ans->end(), ans_right->begin(), ans_right->end());
    }

    return ans;
}



/**
 * @brief Print pair sum in BST
 *      - Space Complexity: O(n)
 *      - Check out hint video for O(log(n)) approach using stacks.
 * 
 * @param root Address of root of BST.
 * @param s Target Sum.
 */
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {

    // Edge Case
    if(root == NULL){
        return;
    }

    // BST to Sorted Vector
    vector<int>* bst_vec = bst_to_sorted_vec(root);

    int i = 0;
    int j = bst_vec->size() - 1;

    while(i < j){

        int a = bst_vec->at(i);
        int b = bst_vec->at(j);
        int c = a + b;

        if(c == s){
            cout << a << " " << b << endl;
            i++;
            j--;
        } else if (c < s){
            i++;
        } else {
            j--;
        }
    }
}

int main(){
    
    // 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
    vector<int>* v = new vector<int>();

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    // v = bst_to_sorted_vec(root_node);

    // for(int i = 0; i < v->size(); i++){
    //     cout << v->at(i) << " ";
    // }
    // cout << endl;

    printNodesSumToS(root_node, 12);

    return 0;
}