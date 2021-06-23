#include <climits>

template <typename T>

class StackUsingArray {

    private:
        T *data;        // Pointer to store address of Stack Array in Heap
        int nextIndex;  
        int capacity;   // To store total capacity of created stack

    
    public:

        StackUsingArray(int arg_capacity){
            this->data = new T[arg_capacity];
            this->nextIndex = 0;
            this->capacity = arg_capacity;
        }


        
        int size(){
            return (this->nextIndex);
        }

        
        
        bool isEmpty(){
            return (this->nextIndex == 0);
        }


        // ** Lec 10.3 - Dynamic Stack **
        void push(int arg_element){

            if(this->nextIndex == this->capacity){

                // 1. Create a new space to accomodate current element
                T *newData = new T[2 * (this->capacity)];

                // 2. Copy content of old array into new array
                for(int i = 0; i < capacity; i++){
                    newData[i] = this->data[i];
                }

                // 3. Update capacity of the stack
                this->capacity *= 2;

                // 4. Delete old array
                delete [] this->data;

                // 5. Update address of array
                this->data = newData;
            }

            this->data[this->nextIndex] = arg_element;
            (this->nextIndex)++;
        }

        /*
        void push(int arg_element){

            if(this->nextIndex == this->capacity){
                cout << "Stack is full. Can't Push " << arg_element << endl;
                return;
            }

            this->data[this->nextIndex] = arg_element;
            (this->nextIndex)++;
        }
        */   


        T pop(){

            if(isEmpty()){
                cout << "Can not Pop. Stack is empty." << endl;
                return (T)0;
            }

            (this->nextIndex)--;

            return (this->data[this->nextIndex]);
        
        }


        T top(){

            if(isEmpty()){
                cout << "Stack is empty." << endl;
                return (T)0;
            }

            return ((this->data)[(this->nextIndex) - 1]);

        }

};