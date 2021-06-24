#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include "TreeNode.h"
using namespace std;


/**
 * @brief [#trees, #recursion] [Lec 11.10] To print nodes in Pre-order traversal of a tree.
 * 
 * @param root Address of the root node of the tree.
 */
void printPreOrder(TreeNode<int>* root) {
    
    int number_child;

    // Edge Case
    if(root == NULL){
        return;
    }
    
    number_child = root->children.size();
    
    // 1. Base Case
    // No need to explicitly write the base case

    // 2. Current Problem
    // Pre-order: First print root then its children
    cout << root->data << " ";

    // 3. Recursive Case
    for(int i = 0; i < number_child; i++){
        printPreOrder(root->children.at(i));
    }

}


/**
 * @brief [#trees, #recursion] [Code 11.6] To print nodes in Post-order traversal of a tree.
 * 
 * @param root Address of the root node of the tree.
 */
void printPostOrder(TreeNode<int>* root) {
    
    int number_child;

    // Edge Case
    if(root == NULL){
        return;
    }

    number_child = root->children.size();

    // 1. Base Case
    if(number_child == 0){
        cout << root->data << " ";
        return;
    }

    // 2. Recursive Case
    for(int i = 0; i < number_child; i++){
        printPostOrder(root->children.at(i));
    }

    // 3. Current Problem
    cout << root->data << " ";
}



/**
 * @brief [#trees, #recursion] [Code 11.5] Count number of leaf node of a tree.
 * 
 * @param root Address of the root node of the tree.
 */
int getLeafNodeCount(TreeNode<int>* root) {
    
    // Edge Case
    if(root == NULL){
        return 0;
    }

    int number_child = root->children.size();
    int total = 0;

    // Base Case
    if(number_child == 0){
        return 1;
    }

    // Recursive Case
    for(int i = 0; i < number_child; i++){
        total += getLeafNodeCount(root->children.at(i));
    }

    return total;
}


/**
 * @brief [#trees, #recursion] [Lec 11.8] To print nodes at a given level.
 * 
 * @param root Address of the root node of the tree.
 * @param level Nodes at which level you want to get printed.
 */
void printAtLevelK(TreeNode<int>* root, int level){

    // 0. Edge Case
    // Handling the edge case so that we can avoid segmentation fault error if someone passes NULL
    if(root == NULL){
        return;
    }

    // 1. Base Case
    if(level == 0){
        cout << root->data << endl;
        return;
    }

    // 2. Recursive Case
    for(int i = 0; i < root->children.size(); i++){
        printAtLevelK(root->children.at(i), level - 1);
    }
}


/**
 * @brief [#trees, #recursion] To return height of a tree.
 * 
 * @param root Address of the root node of the tree.
 * @return int Height of the tree.
 */
int getHeight(TreeNode<int>* root) {
    
    vector<int> vector_height_subtrees;     // Vector to store height of the child nodes
    int max_height = 0;
    int child_height;

    // 1. Base Case
    if(root->children.size() == 0){
        return 1;
    }


    // 2. Recursive Case
    for(int i = 0; i < root->children.size(); i++){
        child_height = getHeight(root->children.at(i));
        vector_height_subtrees.push_back(child_height);
    }

    // 3. Current Problem
    for(int j = 0; j < vector_height_subtrees.size(); j++){

        int curr_height = vector_height_subtrees.at(j);
        
        if(curr_height > max_height){
            max_height = curr_height;
        }
    }

    return (max_height + 1);
}


/**
 * @brief [#trees, #recursion] [Code 11.3] To return the node which holds the data of max value in the tree.
 * 
 * @param root Address of the root node of the tree.
 * @return TreeNode<int>* Address of the node holding the max value in the tree.
 */
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    
    int max_data = INT_MIN;
    int curr_data;
    int max_node_pos;
    vector<TreeNode<int>*> vector_max_nodes;        // Vector to store max nodes of child nodes

    // 1. Base Case
    if(root->children.size() == 0){
        return root;
    }

    // 2. Recursive Case
    for(int i = 0; i < root->children.size(); i++){
        vector_max_nodes.push_back(maxDataNode(root->children.at(i)));
    }

    // 3. Current Problem
    for(int j = 0; j < vector_max_nodes.size(); j++){

        curr_data = vector_max_nodes.at(j)->data;
        if( curr_data > max_data){
            max_data = curr_data;
            max_node_pos = j;
        }

    }

    return vector_max_nodes.at(max_node_pos);
}


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

    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

    TreeNode<int>* node_root2 = takeInputLevelWise();

    printLevelWise(node_root2);

    cout << "Number of nodes: " << countNodes(node_root2) << endl;

    cout << "Sum: " << sumOfNodes(node_root2) << endl;

    cout << "Max Node: " << maxDataNode(node_root2)->data << endl;

    cout << "Height: " << getHeight(node_root2) << endl;


    cout << "Node @ level = 2: " << endl;
    printAtLevelK(node_root2, 2);

    cout << "Number of leaf nodes: " << getLeafNodeCount(node_root2) << endl;

    cout << "Print Pre-Order: "; 
    printPreOrder(node_root2);
    cout << endl;

    cout << "Print Post-Order: "; 
    printPostOrder(node_root2);
    cout << endl;

    return 0;
}