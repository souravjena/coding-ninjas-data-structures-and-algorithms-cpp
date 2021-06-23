class Node{

    public:
        int data;
        Node *next;

        Node(int arg_data){
            this->data = arg_data;
            this->next = NULL;
        }
};


class QueueUsingLL{

    private:
        Node *head;
        Node *tail;
        int size_queue;

    public:

        QueueUsingLL(){
            this->head = NULL;
            this->tail = NULL;
            this->size_queue = 0;
        }


        int getSize() {
            return (this->size_queue);
        }

        
        bool isEmpty() {
            return (this->size_queue == 0);
        }

        
        int front() {

            if(this->head != NULL){
                return (this->head->data);
            }

            return -1;
        }

        
        void enqueue(int data) {

            Node *new_node = new Node(data);
            
            if( this->isEmpty() == 1 ){
                this->head = new_node;
                this->tail = new_node;
            } else {
                // Connect New Node
                (this->tail)->next = new_node;

                // Update Tail
                this->tail = new_node;
            }

            (this->size_queue)++;        
        }

        
        int dequeue() {

            if( this->isEmpty() == 1 ){
                return -1;
            }
            
            int deq_data = (this->head)->data;
            
            Node *temp = this->head;
            
            this->head = (this->head)->next;

            delete temp;

            (this->size_queue)--;

            return deq_data;

        }

};