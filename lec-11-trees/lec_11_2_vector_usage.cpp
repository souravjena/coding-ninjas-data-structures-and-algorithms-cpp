#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> v;                          // Static creation
    vector<int> *vp = new vector<int>();    // Dynamic creation

    for(int i = 0; i < 100; i++){
        v.push_back(i);
        cout << "v.push_back(" << i << ")" << "\t size: " << v.size() << "\t capacity: " << v.capacity() << endl;
    }

    
    // ** DO NOT use [] to access/update elements of a vector **
    
    vp->push_back(10);
    vp->push_back(20);
    vp->push_back(30);

    cout << "vp->size(): " << vp->size() << endl;

    cout << "vp->at(0) = " << vp->at(0) << endl;
    cout << "vp->at(1) = " << vp->at(1) << endl;
    cout << "vp->at(2) = " << vp->at(2) << endl << endl;
    // cout << "vp->at(3) = " << vp->at(3) << endl; // ** This will throw error since at 3 we don't have any element

    cout << "(*vp)[0] = " << (*vp)[0] << endl;
    cout << "(*vp)[1] = " << (*vp)[1] << endl;
    cout << "(*vp)[2] = " << (*vp)[2] << endl;
    cout << "(*vp)[3] = " << (*vp)[3] << endl;      // ** This won't throw any error **

    (*vp)[3] = 999;
    vp->push_back(40);

    cout << "vp->at(3) = " << vp->at(3) << endl;
    cout << "(*vp)[3] = " << (*vp)[3] << endl;      // ** This won't throw any error **
    
    return 0;
}