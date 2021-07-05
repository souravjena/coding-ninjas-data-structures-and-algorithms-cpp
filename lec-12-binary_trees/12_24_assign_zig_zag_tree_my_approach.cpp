#include <iostream>
#include <queue>
#include <vector>
#include "BinaryTreeNodeFn.h"
using namespace std;


void helper_zigZagOrder(BinaryTreeNode<int> *root, int level){

    BinaryTreeNode<int>* new_line_indicator = new BinaryTreeNode<int>(-1);  // Node to indicate printing of new-line
    queue<BinaryTreeNode<int>*> q;
    vector<int> data_levelwise;     // Vector to hold data of BT nodes at a particular level

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
            data_levelwise.push_back(curr_node->data);
        } else {
            
            if(level % 2 != 0){

                for(int i = 0; i < data_levelwise.size(); i++){
                    cout << data_levelwise.at(i) << " ";
                }
                cout << endl;
                data_levelwise.clear();

            } else {
                
                for(int j = data_levelwise.size() - 1; j >= 0; j--){
                    cout << data_levelwise.at(j) << " ";
                }
                cout << endl;
                data_levelwise.clear();
            }

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
                level++;
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

void zigZagOrder(BinaryTreeNode<int> *root) {
    helper_zigZagOrder(root, 1);
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