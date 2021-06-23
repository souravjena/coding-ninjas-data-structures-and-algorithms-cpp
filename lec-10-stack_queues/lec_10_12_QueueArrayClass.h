template <typename T>

class QueueUsingArray{

    private:
        T *arr_data;
        int index_first;
        int index_next;
        int size_queue;
        int capacity_total;

    
    public:
        QueueUsingArray(int arg_capacity_total){

            this->capacity_total = arg_capacity_total;
            this->index_first = 0;
            this->index_next = 0;      
            this->size_queue = 0;

            // Create an empty array of type T in the Heap Memory
            this->arr_data = new T[this->capacity_total];   
        }


        
        int getSize(){
            return (this->size_queue);
        }


        
        bool isEmpty(){
            return (this->size_queue == 0);
        }


        
        T front(){
            
            if(this->isEmpty() == 1){
                cout << "Queue is empty." << endl;
                return (T)0;
            }

            return ( this->arr_data[this->index_first] );
        }

        /*  
            QUEUE
            - FIFO
            - Insert at index_next
            - Remove from index_first
        */

        // Insert Element
        void enqueue(T arg_element){
            
            // 0. If Queue is full return
            if(this->size_queue == this->capacity_total){
                cout << "Queue is full. Can't insert." << endl;
                return;
            }

            // 1. Insert Element
            this->arr_data[this->index_next] = arg_element;


            // 2. Update index_next
            /*
            - We need cyclic index i.e if capacity_total = 5 (index = 0 to 4)
                then when index_next should be 5 then it should be 0
                similarly when index_next should be 6 then it should be 1 like that.
                if index_next should be 2 then it should remain 2 only.
            */
            this->index_next = (this->index_next + 1) % (this->capacity_total);


            // 3. Update size_queue
            (this->size_queue)++;
        
        }


        // ** Lec 10.13 - Dynamic Insertion **
        void enqueue_dyn(T arg_element){

            // 0. If Queue is full return
            if(this->size_queue == this->capacity_total){
                
                // 0.1 Create a new space for a bigger array
                T *new_arr_data = new T[2 * this->capacity_total];

                
                // 0.2 Copy content of older array into new array.
                // ** Make sure to copy the content in the order of the queue. **

                int k = 0;

                for(int i = this->index_first; i < this->capacity_total; i++){
                    new_arr_data[k] = this->arr_data[i];
                    k++;
                }

                for(int i = 0; i < this->index_first; i++){
                    new_arr_data[k] = this->arr_data[i];
                    k++;
                }


                // 0.3 Delete the space occupied by old array
                delete [] this->arr_data;

                // 0.4 Update arr_data;
                this->arr_data = new_arr_data;

                // 0.5 Update indexes;
                this->index_first = 0;
                this->index_next = this->capacity_total; // old capacity
                this->capacity_total *= 2;

            }

            // 1. Insert Element
            this->arr_data[this->index_next] = arg_element;


            // 2. Update index_next
            /*
            - We need cyclic index i.e if capacity_total = 5 (index = 0 to 4)
                then when index_next should be 5 then it should be 0
                similarly when index_next should be 6 then it should be 1 like that.
                if index_next should be 2 then it should remain 2 only.
            */
            this->index_next = (this->index_next + 1) % (this->capacity_total);


            // 3. Update size_queue
            (this->size_queue)++;


        }

        // Remove Element
        T dequeue(){

            // 0. If queue is empty, return
            if(this->isEmpty() == 1){
                cout << "Queue is already empty. Can't remove." << endl;
                return (T)0;
            }


            // 1. Store the element to be removed in a temp space
            T temp = this->arr_data[this->index_first];

            // 2. Update index_first
            /*
            - We need cyclic index i.e if capacity_total = 5 (index = 0 to 4)
                then when index_first should be 5 then it should be 0
                similarly when index_first should be 6 then it should be 1 like that.
                if index_first should be 2 then it should remain 2 only.
            */
            this->index_first = (this->index_first + 1) % (this->capacity_total);

            // 3. Update Size
            (this->size_queue)--;


            // 4. Return the element which was removed
            return (temp);
        }
};