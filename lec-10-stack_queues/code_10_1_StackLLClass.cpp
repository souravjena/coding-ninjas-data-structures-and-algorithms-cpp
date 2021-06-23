
class Node {
    public :
        int data;
        Node *next;

        Node(int data) {
            this->data = data;
            next = NULL;
        }
};

class Stack {
	// Define the data members

    private:
        Node *head;
        int sizeLL;

    public:
        Stack() {
            // Implement the Constructor
            this->head = NULL;
            this->sizeLL = 0;
        }

        /*----------------- Public Functions of Stack -----------------*/

        int getSize() {
            // Implement the getSize() function
            return (this->sizeLL);
        }

        
        
        bool isEmpty() {
            // Implement the isEmpty() function
            if( (this->sizeLL) == 0 ){
                return true;
            }

            return false;
        }

        
        
        void push(int element) {
            // Implement the push() function
            Node *newNode = new Node(element);

            newNode->next = this->head;
            this->head = newNode;

            this->sizeLL += 1;
        }

        
        
        int pop() {
            // Implement the pop() function
            if( this->isEmpty() == false ){
                
                /*  
                // ** WRONG **
                Node *temp = this->head;

                delete (this->head);   // ** This is deleting the space allocated to Head i.e deleting the head variable **

                this->head = temp->next;
                this->sizeLL -= 1;

                return (temp->data);
                */

                int pop_data = (this->head)->data;
                Node *temp = this->head;
                
                this->head = temp->next;

                delete temp;    // ** Delete the space allocated to old head node BUT not the space allocated to head variable. **

                this->sizeLL -= 1;

                return (pop_data);

            }

            return -1;
        }

        
        
        int top() {
            // Implement the top() function
            if( this->isEmpty() == false ){

                return ( (this->head)->data );
            }

            return -1;
        }

        
        void print_LL(){

            Node *currNode = this->head;
            
            while(currNode != NULL){
                cout << currNode->data << " -> ";

                currNode = currNode->next;
            }

            cout << "." << endl;
        }
};