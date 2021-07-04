#include <iostream>
#include <queue>
#include "BinaryTreeNodeFn.h"
using namespace std;


void printLevelWise(BinaryTreeNode<int> *root) {
    
    BinaryTreeNode<int>* new_line_indicator = new BinaryTreeNode<int>(-1);  // Node to indicate printing of new-line
    queue<BinaryTreeNode<int>*> q;

    if(root == NULL){
        return;
    }

    /*
    - Since there is only single root of any BT, hence we are pushing root and new_line_indicator node
      so that root is printed and after that a new line.
    */
    q.push(root);
    q.push(new_line_indicator);

    // Print nodes in the q.
    while(q.empty() == false){

        // Take out the front node in the q.
        BinaryTreeNode<int>* curr_node = q.front();
        q.pop();
        
        // If new_line_indicator node is encountered print new line else the element.
        if(curr_node != new_line_indicator){
            cout << curr_node->data << " ";
        } else {
            cout << endl;

            if(q.empty() == true){
                return;
            } else {
                /*
                - ** [#important] ** 
                - When a new_line_node indicator is encountered by then we will have
                  all the child nodes at a particular level in the q already.
                - Since in each loop we are pushing all the child nodes of a node in the q.
                */
                q.push(new_line_indicator);
            }
        }

        // Push child nodes
        if(curr_node->left != NULL){
            q.push(curr_node->left);
        }

        if(curr_node->right != NULL){
            q.push(curr_node->right);
        }
    } 
}


int main(){

    // 1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    printLevelWise(root_node);

    return 0;
}