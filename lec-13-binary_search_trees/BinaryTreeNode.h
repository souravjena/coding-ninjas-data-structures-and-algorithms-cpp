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