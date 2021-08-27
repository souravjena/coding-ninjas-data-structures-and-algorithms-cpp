#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> min_pq;

    for(int i = 0; i < input.size(); i++){

    	for(int j = 0; j < input.at(i)->size(); j++){
    		min_pq.push(input.at(i)->at(j));
    	}

    }
    
    while(min_pq.empty() == false){
    	ans.push_back(min_pq.top());
    	min_pq.pop();
    }

    return ans;
}


int main(){

	vector<int> ans;
	vector<vector<int>*> vec_arr;

	vector<int>* v1 = new vector<int>();
	vector<int>* v2 = new vector<int>();
	vector<int>* v3 = new vector<int>();
	vector<int>* v4 = new vector<int>();

    v1->push_back(1);
    v1->push_back(5);
    v1->push_back(9);

    v2->push_back(45);
    v2->push_back(90);

    v3->push_back(2);
    v3->push_back(6);
    v3->push_back(78);
    v3->push_back(100);
    v3->push_back(234);

    v4->push_back(0);

    vec_arr.push_back(v1);
    vec_arr.push_back(v2);
    vec_arr.push_back(v3);
    vec_arr.push_back(v4);

    ans = mergeKSortedArrays(vec_arr);

    for(int i = 0; i < ans.size(); i++){
    	cout << ans.at(i) << endl;
    }

    return 0;
}