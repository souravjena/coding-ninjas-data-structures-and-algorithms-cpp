#include <iostream>
#include "BinaryTreeNodeFn.h"
using namespace std;


template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;

    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

class LLReturn{
    public:
        Node<int>* head;
        Node<int>* tail;
};


void print_LL(Node<int>* arg_head){

    while(arg_head != NULL){
        cout << arg_head->data << " -> ";

        arg_head = arg_head->next;
    }

    cout << "." << endl;
}


/**
 * @brief [#important, #recursion] Construct sorted LL using a BST.
 * 
 * @param root_bt Address of the root node of the BST.
 * @return LLReturn Head and Tail node of the LL.
 */
LLReturn helper_constructLinkedList(BinaryTreeNode<int>* root_bt){

    LLReturn ans, ans_left, ans_right;

    // 1. Base Case
    if(root_bt == NULL){
        ans.head = NULL;
        ans.tail = NULL;

        return ans;
    }

    
    // 2. Recursive Case
    ans_left = helper_constructLinkedList(root_bt->left);
    ans_right = helper_constructLinkedList(root_bt->right);

    
    // 3. Current Problem
    Node<int>* curr_node = new Node<int>(root_bt->data);

    // 3.1 Update head of the LL
    if(ans_left.head != NULL){
        ans.head = ans_left.head;
    } else {
        ans.head = curr_node;
    }
    
    // 3.2 Connect Current Node to the final LL
    if(ans_left.tail != NULL){
        ans_left.tail->next = curr_node;
    } 
    curr_node->next = ans_right.head;

    // 3.3 Update tail of the LL
    if(ans_right.tail != NULL){
        ans.tail = ans_right.tail;
    } else {
        ans.tail = curr_node;
    }
    
    return ans;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    return (helper_constructLinkedList(root).head);
}


int main(){
    
    BinaryTreeNode<int>* root_node = input_level_wise_BT();
    cout << endl << endl;

    print_level_wise_BT(root_node);
    cout << "______________________" << endl;

    Node<int>* head_ll = constructLinkedList(root_node);
    print_LL(head_ll);

    return 0;
}