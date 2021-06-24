#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

/**
 * @brief [#important, #queue][11.5] Take level-wise input of nodes of a tree. 
 * 
 * @return TreeNode<int>* Address of the root node of the tree.
 */
TreeNode<int>* takeInputLevelWise(){

    int node_data;
    int num_child;
    queue<TreeNode<int>*> queue_pending_nodes;

    cout << "Enter root node data: ";
    cin >> node_data;
    
    TreeNode<int>* root_node = new TreeNode<int>(node_data);

    queue_pending_nodes.push(root_node);

    while(queue_pending_nodes.size() != 0){

        // 1. Take the front node from the queue

        TreeNode<int>* front_node = queue_pending_nodes.front();
        queue_pending_nodes.pop();

        // 2. Number of children?
        cout << "Enter # of children of {" << front_node->data << "} node: ";
        cin >> num_child;

        
        for (int i = 0; i < num_child; i++){

            // 3. Create children nodes
            cout << "\t" << "Enter data of child node #" << i + 1 << " : ";
            cin >> node_data;

            TreeNode<int>* child_node = new TreeNode<int>(node_data);
            
            // 4. Connect them with the parent node
            front_node->children.push_back(child_node);

            // 5. Push the child node in the queue
            queue_pending_nodes.push(child_node);
        }

    }

    return root_node;
}


/**
 * @brief [#recursion][11.4] To take tree input from the user recursively.
 * 
 * @return TreeNode<int>* Address of the root node.
 */
TreeNode<int>* takeInput(){

    int data_node;
    int number_child;

    cout << "Enter node data: ";
    cin >> data_node;
    TreeNode<int> *node_root = new TreeNode<int>(data_node);

    cout << "Enter # of children of this [" << data_node << "] node: ";
    cin >> number_child;

    for(int i = 0; i < number_child; i++){
        TreeNode<int> *node_child = takeInput();
        node_root->children.push_back(node_child);
    }

    return node_root;
}



/**
 * @brief [#recursion][11.4] Print tree using recursion.
 * 
 * @param root Root node of the tree.
 */
void printTree(TreeNode<int>* root){

    // Edge Case (not the Base Case)
    if(root == NULL){
        return;
    }

    // 1. Current Problem
    cout << root->data << ": ";

    /* 
        ** Base Case **
        - If there are no children of the current node then return.
        - There is no need to explicity write this base case since
          the program won't enter the for loops if root->children.size() == 0
    */
    for(int i = 0; i < root->children.size(); i++){
        cout << (root->children.at(i))->data << ", ";
    }
    cout << endl;

    // 3. Recursive Case
    for(int j = 0; j < root->children.size(); j++){
        printTree(root->children.at(j));
    }

}

int main(){

    // TreeNode<int>* node_root = takeInput();

    // printTree(node_root);


    TreeNode<int>* node_root2 = takeInputLevelWise();

    printTree(node_root2);

    return 0;
}