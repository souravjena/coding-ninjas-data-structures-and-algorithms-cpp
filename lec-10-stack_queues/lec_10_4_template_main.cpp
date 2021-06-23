#include <iostream>
using namespace std;
#include "lec_10_4_template_PairClass.cpp"

int main(){

    Pair<int, int> p1;

    p1.setX(10);
    p1.setY(11);
    cout << p1.getX() << "\t" << p1.getY() << endl;



    Pair<int, double> p2;
    
    p2.setX(10.99);
    p2.setY(11.78);
    cout << p2.getX() << "\t" << p2.getY() << endl;



    Pair<double, double> p3;
    
    p3.setX(10.99);
    p3.setY(11.78);
    cout << p3.getX() << "\t" << p3.getY() << endl;



    // ** IMPORTANT - Triplets **
    Pair<Pair<int, int>, int> p_triplet;
    
    p_triplet.setX(p1);
    p_triplet.setY(132);
    cout << p_triplet.getX().getX() << "\t" << p_triplet.getX().getY() << "\t" << p_triplet.getY() << endl;   

}