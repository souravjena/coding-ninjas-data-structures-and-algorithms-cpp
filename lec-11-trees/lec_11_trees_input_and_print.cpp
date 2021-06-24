#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;


/**
 * @brief [#trees, #recursion][Code 11.2] To find sum of all nodes in a tree.
 * 
 * @param root Address of the root node.
 * @return int Sum of all nodes in the tree.
 */
int sumOfNodes(TreeNode<int>* root) {
    
    int sum;

    // Edge Case
    if(root == NULL){
        return 0;
    }

    // 1. Base Case
    // if (root->children.size() == 0) then sum = 0. so, return 0.
    // No need to explicitly write this since the program won't enter the for loop if size == 0.

    // 2. Current Problem
    sum = root->data;

    // 3. Recursive Case
    for(int i = 0; i < root->children.size(); i++){
        sum += sumOfNodes(root->children.at(i));
    }

    return sum;
}

/**
 * @brief [#trees, #recursion][Lec 11.6] To count number of nodes in the tree.
 * 
 * @param root Address of the root node of the tree.
 * @return int Number of nodes in the tree.
 */
int countNodes(TreeNode<int>* root){

    // Edge Case
    if(root == NULL){
        return 0;
    }

    int count;

    // 1. Base Case
    // if (root->children.size() == 0) then count itself and return. i.e return 1.
    // No need to explicitly write this since the program won't enter the for loop if size == 0.
    
    // 2. Current Problem
    count = 1;  // Count itself

    // 3. Recursive Case
    for(int i = 0; i < root->children.size(); i++){
        count += countNodes(root->children.at(i));
    }

    return count;
}


/**
 * @brief [#important, #trees, #queue][Code 11.1] LEVEL ORDER PRINTING of tree i.e Level-wise printing of tree.
 * 
 * @param root Address of the root node of the tree.
 */
void printLevelWise(TreeNode<int>* root) {

    queue<TreeNode<int>*> queue_pending_nodes;

    // 1. Push root in the pending nodes queue.
    // This queue stores the nodes whose children we haven't printed yet.
    queue_pending_nodes.push(root);

    // 2. Print all the nodes in the queue and their children
    while(queue_pending_nodes.size() != 0){

        // 2.1 Take out the front element in queue.
        TreeNode<int>* front_node = queue_pending_nodes.front();
        queue_pending_nodes.pop();

        cout << front_node->data << ": ";

        // 2.2 Print its children
        for(int i = 0; i < front_node->children.size(); i++){
            TreeNode<int>* child_node = front_node->children.at(i);

            cout << child_node->data << ", ";

            // 2.3 Push these children in the queue so that its children can be printed
            queue_pending_nodes.push(child_node);
        }

        cout << endl;
    }
}

/**
 * @brief [#important, #trees, #queue][Lec 11.5] Take level-wise input of nodes of a tree. 
 * 
 * @return TreeNode<int>* Address of the root node of the tree.
 */
TreeNode<int>* takeInputLevelWise(){

    int node_data;
    int num_child;
    queue<TreeNode<int>*> queue_pending_nodes;

    // 1. Create root node
    cout << "Enter root node data: ";
    cin >> node_data;
    
    TreeNode<int>* root_node = new TreeNode<int>(node_data);

    // 2. Push root node to pending nodes queue.
    // This queue signifies the nodes whose children we are suppose to get from the user.
    queue_pending_nodes.push(root_node);

    // 3. Get children of all the nodes in the queue.
    while(queue_pending_nodes.size() != 0){

        // 3.1. Take the front node from the queue
        TreeNode<int>* front_node = queue_pending_nodes.front();
        queue_pending_nodes.pop();

        // 3.2. Number of children?
        cout << "Enter # of children of {" << front_node->data << "} node: ";
        cin >> num_child;

        
        for (int i = 0; i < num_child; i++){

            // 3.3. Create children nodes
            cout << "\t" << "Enter data of child node #" << i + 1 << " : ";
            cin >> node_data;

            // [#important] 
            // If we use static allocation here then then scope of the node will be
            // the current iteration only and after the iteration this memory will get deallocated.
            // Hence we are using dynamic allocation here.
            TreeNode<int>* child_node = new TreeNode<int>(node_data);
            
            // 3.4. Connect them with the parent node
            front_node->children.push_back(child_node);

            // 3.5. Push the child node in the queue
            queue_pending_nodes.push(child_node);
        }

    }

    // 4. return the root_node.
    return root_node;
}


/**
 * @brief [#trees, #recursion][Lec 11.4] To take tree input from the user recursively.
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
 * @brief [#trees, #recursion][Lec 11.4] Print tree using recursion.
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

    printLevelWise(node_root2);

    cout << "Number of nodes: " << countNodes(node_root2) << endl;

    cout << "Sum: " << sumOfNodes(node_root2) << endl;

    return 0;
}