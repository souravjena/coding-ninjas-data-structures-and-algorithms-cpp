#include <iostream>
using namespace std;
#include "lec_10_5_template_StackArrayClass.cpp"

int main(){
	StackUsingArray<char> s(4);

	s.push('a');
	s.push('b');
	s.push('c');
	s.push('d');
	s.push('e');

	cout << s.top() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.size() << endl;
	cout << s.isEmpty() << endl;
}