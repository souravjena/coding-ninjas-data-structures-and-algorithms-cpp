#include <iostream>
#include "TreeNodeFn.h"
using namespace std;


class Pair{

    public:
        TreeNode<int>* first_largest;
        TreeNode<int>* second_largest;

        Pair(){
            this->first_largest = NULL;
            this->second_largest = NULL;
        }

};


#include <vector>

class Pair{

    public:
        TreeNode<int>* first_largest;
        TreeNode<int>* second_largest;

        Pair(){
            this->first_largest = NULL;
            this->second_largest = NULL;
        }

};


Pair helper_getSecondLargestNode(TreeNode<int>* root) {
    
    Pair ans;
    int num_child;
    vector<TreeNode<int>*> v;

    int data_large, index_large, data_second, index_second;

    // Edge Case
    if(root == NULL){
        return ans;
    }

    num_child = root->children.size();

    // 1. Base Case (Leaf Node encountered)
    if(num_child == 0){
        ans.first_largest = root;
        ans.second_largest = NULL;

        return ans;
    }

    
    // 2. Recursive Case
    for(int i = 0; i < num_child; i++){

       Pair child_ans = helper_getSecondLargestNode(root->children.at(i));

        if(child_ans.first_largest != NULL){
            v.push_back(child_ans.first_largest);
        }

        if(child_ans.second_largest != NULL){
            v.push_back(child_ans.second_largest);
        }
    }

    // 3. Current Problem
    v.push_back(root);

    TreeNode<int> dummy_node(INT_MIN);
    ans.first_largest = &dummy_node;
    ans.second_largest = &dummy_node;

    // Identify Largest and Second Largest node in the vector v
    for(int i = 0, j = 1; i < v.size(); i++, j++){
        int a, b;

        a = v.at(i)->data;
   
        if(j >= v.size()){
            b = INT_MIN;
        } else {
            b = v.at(j)->data;
        }

        if(a >= b){

            if( (a > ans.first_largest->data) && (a > ans.second_largest->data) ){
                ans.second_largest = ans.first_largest;
                ans.first_largest = v.at(i);

            
            } else if ( (a < ans.first_largest->data) && (a > ans.second_largest->data) ){
                ans.second_largest = v.at(i);
            }

            if( (b > ans.second_largest->data) && (b != ans.first_largest->data) ){
                ans.second_largest = v.at(j);
            
            } else if ((b > ans.second_largest->data) && (b == ans.first_largest->data)) {
                ans.second_largest = &dummy_node;
            }
            

        } 
        
        if(a < b){

            if( (b > ans.first_largest->data) && (b > ans.second_largest->data) ){
                ans.second_largest = ans.first_largest;
                ans.first_largest = v.at(j);
            
            } else if ( (b < ans.first_largest->data) && (b > ans.second_largest->data) ){
                ans.second_largest = v.at(j);
            }

            if(a > ans.second_largest->data){
                ans.second_largest = v.at(i);
            }
        }
    }

    return ans;
}


TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {

    // if(helper_getSecondLargestNode(root).second_largest->data == INT_MIN){
    //     return NULL;
    // }

    return(helper_getSecondLargestNode(root).second_largest);
}

int main(){

    // 10 3 20 30 40 2 40 50 0 0 0 0 

    TreeNode<int>* root_node = takeInputLevelWise();
    // // cout << endl << endl;
    
    printLevelWise(root_node);
    cout << endl << endl;

    cout << getSecondLargestNode(root_node)->data << endl;

    cout << INT_MIN << endl;

}