#include "Stack.h"
#include <iostream>

using namespace std;

int main()
{
	Stack s1;
	Stack s2;

	cout << "Testing the stacks: s1\ts2." << endl;
	cout << "Test if the first stack is empty: " << s1.isEmpty() << endl;
	cout << "Test if the second stack is empty: " << s2.isEmpty() << endl;
	for (int i = 0; i < 3; i++) {
		s1.push(i);
		cout << "Pushing " << i << " on s1" << endl;
	}
	cout << "Test if the first stack is empty: " << s1.isEmpty() << endl;
	for (int i = 0; i < 5; i++) {
		s2.push(i + 2);
		cout << "Pushing " << i + 2 << " on s2" << endl;
	}
	for (int i = 0; i < 3; i++) {
		cout << "Popping from s1: " << s1.pop() << endl;
	}
	cout << "Test if the first stack is empty: " << s1.isEmpty() << endl;
	for (int i = 0; i < 4; i++) {
		cout << "Popping from s2: " << s2.pop() << endl;
	}
	cout << "Test if the first stack is empty: " << s1.isEmpty() << endl;
	cout << "Popping from s2: " << s2.pop() << endl;
	cout << "Test if the first stack is empty: " << s1.isEmpty() << endl;
	return 0;
}
