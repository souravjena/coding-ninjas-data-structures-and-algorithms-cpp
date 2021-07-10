#include <iostream>
#include "BinaryTreeNodeFn.h"
using namespace std;

// Look at notes for explanation
int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    
    // 1. Base Case
    if(root == NULL){
        return -1;
    }

    if( (root->data == a) || (root->data == b) ){
        return root->data;
    }

    
    // 2. Recursive Case
    int l_lca = getLCA(root->left, a, b);
    int r_lca = getLCA(root->right, a, b);

    
    // 3. Current
    if(l_lca != -1 && r_lca != -1){
        return root->data;
    }

    if(l_lca != -1 && r_lca == -1){
        return l_lca;
    }

    if(l_lca == -1 && r_lca != -1){
        return r_lca;
    }

}

int main(){
    
    // 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
    int n1 = 2;
    int n2 = 6;

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    cout << getLCA(root_node, n1, n2) << endl;

    return 0;
}