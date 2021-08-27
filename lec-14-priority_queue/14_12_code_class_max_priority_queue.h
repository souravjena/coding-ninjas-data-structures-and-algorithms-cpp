#include <vector>
#include <climits>

class PriorityQueue {
	// Declare the data members here
	vector<int> pq;
    
   
    public:
        PriorityQueue() {
            // Implement the constructor here

        }

        /**************** Implement all the public functions here ***************/
		
    	int getMax() {
            // Implement the getMax() function here
            if(isEmpty() == true){
                return INT_MIN;
            }
            
            return (pq.at(0));
        }
    
        int getSize() { 
            // Implement the getSize() function here
            return (this->pq.size());
        }

        bool isEmpty() {
            // Implement the isEmpty() function here
            return (this->pq.size() == 0);

        }
    
    
        
    	void insert(int element) {
            // Implement the insert() function here
            
            int currIndex, parentIndex, temp;
            
            // 1. Insert element in the vector
            this->pq.push_back(element);
            
            // Get current node index
            currIndex = this->getSize() - 1;
            
            // 2. Up-heapify
            // End the loop when you reach the root of the CBT
            while(currIndex > 0){
                
                parentIndex = (currIndex - 1)/2;
                
                // 2.1 Compare currNode with its parent Node
                // 2.2 Swap if required else break out
        		if(pq.at(currIndex) > pq.at(parentIndex)){
                    temp = pq.at(currIndex);
                    
                    pq.at(currIndex) = pq.at(parentIndex);
                    pq.at(parentIndex) = temp;
                } else {
                    break;
                }
                
                // 2.3 Update currIndex
                currIndex = parentIndex;
            }
        }

        

        int removeMax() {
            // Implement the removeMax() function here
            
            int ans, temp;
            int parentIndex, leftChildIndex, rightChildIndex, maxIndex;
            int lastIndex = this->getSize() - 1;
            
            // Handle Edge Case
            if(isEmpty()){
            	return INT_MIN;
        	}
            
            // 1. Store the max element so that it can be returned.
            ans = pq.at(0);
            
            // 2. Swap root(the max element) with last element.
            // 3. Remove the last element.
            pq.at(0) = pq.at(lastIndex);
            pq.pop_back();
            
            // 4. Update lastIndex
            lastIndex = this->getSize() - 1;
            
            // 5. Down Heapify
            
            /*
            - If leftChildIndex > lastIndex then that would imply that the current node has no children.
            - parentIndex < leftChildIndex < rightChildIndex
            */
            
            parentIndex = 0;
            leftChildIndex = 1;
            rightChildIndex = 2;
            
            while(leftChildIndex <= lastIndex){
                
                maxIndex = parentIndex;
                
                // Compare nodes and assign maxIndex
                if(this->pq.at(leftChildIndex) > this->pq.at(maxIndex)){
                    maxIndex = leftChildIndex;
                }
                
                // leftIndex out of bound we are checking in the while condition
                // but is rightChildIndex is out of bound we are not checking hence
                // using checking it here.
                if(rightChildIndex <= lastIndex){
                    
                    if(this->pq.at(rightChildIndex) > this->pq.at(maxIndex)){
                        maxIndex = rightChildIndex;
                    }
                    
                }
                
                // If both left child and right child are smaller than parent then
                // maxIndex won't change so break because the node is at correct position
                if(maxIndex == parentIndex){
                    break;
                }
                
                
                // Swap parent with maxIndex element
                temp = this->pq.at(maxIndex);
                this->pq.at(maxIndex) = this->pq.at(parentIndex); 
                this->pq.at(parentIndex) = temp;
                
                // Update Indexes
                parentIndex = maxIndex;
                leftChildIndex = (2 * parentIndex) + 1;
                rightChildIndex = (2 * parentIndex) + 2;
            }
            
            return ans;
        }	
};