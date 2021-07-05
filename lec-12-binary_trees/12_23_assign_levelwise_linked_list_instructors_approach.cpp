#include <iostream>
#include <queue>
#include <vector>
// #include "BinaryTreeNodeFn.h"
using namespace std;


template <typename T>
class BinaryTreeNode {
    public: 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


template <typename T>
class Node {
    public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data=data;
        this->next=NULL;
    }
};


void print_LL(Node<int> *arg_head){

    while(arg_head != NULL){
        cout << arg_head->data << " -> ";

        arg_head = arg_head->next;
    }

    cout << "." << endl;
}

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




/**
 * @brief Constructs LL of each level in a BT.
 * 
 * @param root Address of BT.
 * @return vector<Node<int>*> Vector containing head nodes of each LL. 
 */
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {

    vector<Node<int>*> ans_v;       // Vector to hold head nodes of LLs
    vector<int> data_levelwise;     // Vector to hold data of BT nodes at a particular level
    queue<BinaryTreeNode<int>*> q;  // Queue to hold pending BT nodes
    BinaryTreeNode<int>* new_level_indicator = new BinaryTreeNode<int>(-1);     // Dummy BT node to indicate new level
                                                                                // Could use NULL here also as address.

    Node<int>* node_ll_head = NULL;
    Node<int>* node_ll_tail = NULL;

    // Edge Case
    if(root == NULL){
        return ans_v;
    }


    /*
    - Since there is only single root of any BT, hence we are pushing root and new_level_indicator node
      so that root level will have just one LL node.
    */
    q.push(root);
    q.push(new_level_indicator);


    while(q.empty() == false){

        // Take out the front node in the q.
        BinaryTreeNode<int>* node_bt = q.front();
        q.pop();

        // If new_level_indicator is not encountered then push element in the LL.
        if(node_bt != new_level_indicator){
            
            // If LL is empty
            if( (node_ll_head == NULL) && (node_ll_tail == NULL) ){
                node_ll_head = new Node<int>(node_bt->data);
                node_ll_tail = node_ll_head;
                // ans_v.push_back(node_ll_head);
            
            } else {
                node_ll_tail->next = new Node<int>(node_bt->data);
                node_ll_tail = node_ll_tail->next;
            }

        
        } else {

            // Push head of the LL in ans vector.
            ans_v.push_back(node_ll_head);
            
            // Clear head and tail for next level.
            node_ll_head = NULL;
            node_ll_tail = NULL;
            
            // Push new_level_indicator in the q.
            if(q.empty() == true){
                // If the q is empty after NULL that would mean that there are no elements remaining in the BT.
                // So we can safely return.
                return ans_v;
            } else {
                /*
                - ** [#important] ** 
                - When a new_line_node indicator is encountered by then we will have
                  all the child nodes at a particular level in the q already.
                - Since in each loop we are pushing all the child nodes of a node in the q.
                */
                q.push(new_level_indicator);
            }   
        }

        // Push child nodes of current BT node
        if(node_bt->left != NULL){
            q.push(node_bt->left);
        }

        if(node_bt->right != NULL){
            q.push(node_bt->right);
        }
    }

    return ans_v;
}



int main(){

    // 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    vector<Node<int>*> v = constructLinkedListForEachLevel(root_node);

    for(int i = 0; i < v.size(); i++){
        print_LL(v.at(i));
    }

    return 0;
}