#include <vector>
using namespace std;

template <typename T>
class TreeNode {
    public:
        T data;                             // data of template type
        vector<TreeNode<T>*> children;      // vector of TreeNode pointer type. 
                                            // This vector will hold address of children nodes

        // Constructor to assign data at the time of creation of a TreeNode
        TreeNode(T arg_data){
            this->data = arg_data;
        }
};