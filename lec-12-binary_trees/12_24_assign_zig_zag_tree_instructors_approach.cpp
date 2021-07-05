#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include "BinaryTreeNodeFn.h"
using namespace std;

/**
 * @brief [#important, #BT, #stack] Print BT in zig-zag order. Odd levels, L to R. Even levels, R to L.
 * 
 * @param root Address of root node of BT.
 */
void zigZagOrder(BinaryTreeNode<int> *root) {
    
    stack<BinaryTreeNode<int>*> s1, s2;      // s1 = L to R, s2 = R to L

    // Edge Case
    if(root == NULL){
        return;
    }


    s1.push(root);


    // Odd level nodes push in s1. Its children in s2 first left child then right.
    // Even level nodes push in s2. Its children in s1 first right child then left.

    while( (s1.empty() == false) || (s2.empty() == false) ){

        if(s2.empty() == true){

            while(s1.empty() == false){
                cout << s1.top()->data << " ";

                if(s1.top()->left != NULL){
                    s2.push(s1.top()->left);
                }

                if(s1.top()->right != NULL){
                    s2.push(s1.top()->right);
                }

                s1.pop();
            }

            cout << endl;

        
        } else if (s1.empty() == true){

            while(s2.empty() == false){
                cout << s2.top()->data << " ";

                if(s2.top()->right != NULL){
                    s1.push(s2.top()->right);
                }

                if(s2.top()->left != NULL){
                    s1.push(s2.top()->left);
                }

                s2.pop();
            }

            cout << endl;
        }
    }

}


int main(){

    // 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    zigZagOrder(root_node);

    return 0;
}