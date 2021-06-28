#include <iostream>
#include <queue>
using namespace std;

template <typename T>

class BinaryTreeNode {

    public:
        T data;
        BinaryTreeNode<T>* left;
        BinaryTreeNode<T>* right;

        BinaryTreeNode(T arg_data){
            this->data = arg_data;

            this->left = NULL;
            this->right = NULL;
        }

        ~BinaryTreeNode(){
            
            // 1. Delete Left Child Node
            delete (this->left);     

            // 2. Delete Right Child Node   
            delete (this->right);

            // 3. Delete the Parent Node itself
        }
};


/**
 * @brief Print Binary Tree Level-Wise.
 * 
 * @param root Address of root node of the Binary Tree.
 */
void print_level_wise_BT(BinaryTreeNode<int> *root) {

    queue<BinaryTreeNode<int>*> q;

    // Edge Case
    if(root == NULL){
        return;
    }

    q.push(root);

    while(q.empty() == false){

        BinaryTreeNode<int>* pending_node = q.front();
        q.pop();

        cout << pending_node->data << ":";

        if(pending_node->left == NULL){
            cout << "L:" << -1 << ",";
        } else {
            cout << "L:" << pending_node->left->data << ",";
            q.push(pending_node->left);
        }
        
        
        if(pending_node->right == NULL){
            cout << "R:" << -1;
        } else {
            cout << "R:" << pending_node->right->data;
            q.push(pending_node->right);
        }

        cout << endl;
    }
}


BinaryTreeNode<int>* input_level_wise_BT(){

    int root_data;
    queue<BinaryTreeNode<int>*> q_pending_nodes;

    cout << "Enter root data: ";
    cin >> root_data;

    if(root_data == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root_node = new BinaryTreeNode<int>(root_data);

    q_pending_nodes.push(root_node);


    while(q_pending_nodes.empty() == false){

        int node_data;

        BinaryTreeNode<int>* pending_node = q_pending_nodes.front();
        q_pending_nodes.pop();

        
        cout << "Enter Left Node of " << pending_node->data << ": ";
        cin >> node_data;

        if(node_data != -1){
            BinaryTreeNode<int>* left_node = new BinaryTreeNode<int>(node_data);

            pending_node->left = left_node;

            q_pending_nodes.push(left_node);
        }

        
        cout << "Enter Right Node of " << pending_node->data << ": ";
        cin >> node_data;
        
        if(node_data != -1){
            BinaryTreeNode<int>* right_node = new BinaryTreeNode<int>(node_data);

            pending_node->right = right_node;
            
            q_pending_nodes.push(right_node);
        }
    }

    return root_node;
}