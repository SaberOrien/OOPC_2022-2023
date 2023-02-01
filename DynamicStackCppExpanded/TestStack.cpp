#include "Stack.h"
#include <iostream>

using namespace std;
void testByValue(Stack s);
void testByRef(Stack& s);
void testByAssignments();
void testTheSameSize();
void testSmallToBig();
void testBigToSmall();
void testSelfToSelf();

int main()
{
	Stack s1;
	cout << "Testing the stack: s1.\n" << endl;
	cout << "Test if the first stack is empty: " << s1.isEmpty() << endl;
	for (int i = 0; i < 3; i++) {
		s1.push(i);
		cout << "Pushing " << i << " on s1" << endl;
	}
	cout << "\nInitializing s2 as a copy of current s1.\n" << endl;
	Stack s2(s1);
	testByValue(s1);
	for (int i = 0; i < 3; i++) {
		cout << "Popping from s1: " << s1.pop() << endl;
	}
	cout << "\nTesting the stack: s2.\n" << endl;
	testByRef(s2);
	for (int i = 0; i < 3; i++) {
		cout << "Popping from s2: " << s2.pop() << endl;
	}
	testByAssignments();
	return 0;
}

void testByValue(Stack s)
{
	cout << "--Testing by value.--" << endl;
	cout << "\nTest if the stack is empty: " << s.isEmpty() << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Popping from s: " << s.pop() << endl;
	}
	cout << "Test if the stack is empty: " << s.isEmpty() << endl;
	for (int i = 1; i < 4; i++) {
		s.push(i * 7);
		cout << "Pushing " << i * 7 << " on s" << endl;
	}
	cout << "\n--Returning to main--\n" << endl;
}

void testByRef(Stack& s)
{
	cout << "\n--Testing by ref--\n" << endl;
	cout << "Test if the stack is empty: " << s.isEmpty() << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Popping from s: " << s.pop() << endl;
	}
	cout << "Test if the stack is empty: " << s.isEmpty() << endl;
	for (int i = 1; i < 4; i++) {
		s.push(i * 7);
		cout << "Pushing " << i * 7 << " on s" << endl;
	}
	cout << "\n--Returning to main--\n" << endl;
}

void testByAssignments()
{
	cout << "\n\n---Testing assigning stacks---\n" << endl;
	cout << "--Same size to same size--\n" << endl;
	testTheSameSize();
	cout << "\n\n--Small to big--\n" << endl;
	testSmallToBig();
	cout << "\n\n--Big to small--\n" << endl;
	testBigToSmall();
	cout << "\n\n--Self assignment--\n" << endl;
	testSelfToSelf();
}

void testTheSameSize()
{
	Stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	cout << "Pushed 1, 2, 3 on s1" << endl;
	Stack s2;
	s2.push(7);
	s2.push(8);
	s2.push(9);
	cout << "Pushed 7, 8, 9 on s2" << endl;
	cout << "Assigning s2 to s1" << endl;
	s1 = s2;
	for (int i = 0; i < 3; i++) {
		cout << "From s2: " << s2.pop() << endl;
		cout << "From s1: " << s1.pop() << endl;
	}
}

void testSmallToBig()
{
	Stack s3;
	s3.push(1);
	s3.push(2);
	s3.push(3);
	cout << "Pushed 1, 2, 3 on s3" << endl;
	Stack s4;
	s4.push(7);
	s4.push(8);
	cout << "Pushed 7, 8 on s4" << endl;
	cout << "Assigning s4 to s3" << endl;
	s3 = s4;
	cout << "Test if the stack s3 is empty: " << s3.isEmpty() << endl;
	cout << "Test if the stack s4 is empty: " << s4.isEmpty() << endl;
	for (int i = 0; i < 2; i++) {
		cout << "From s3: " << s3.pop() << endl;
	}
	cout << "Test if the stack s3 is empty: " << s3.isEmpty() << endl;
	for (int i = 0; i < 2; i++) {
		cout << "From s4: " << s4.pop() << endl;
	}
	cout << "Test if the stack s4 is empty: " << s4.isEmpty() << endl;
}

void testBigToSmall()
{
	Stack s5;
	s5.push(1);
	s5.push(2);
	s5.push(3);
	cout << "Pushed 1, 2, 3 on s5" << endl;
	Stack s6;
	s6.push(7);
	s6.push(8);
	cout << "Pushed 7, 8 on s6" << endl;
	cout << "Assigning s5 to s6" << endl;
	s6 = s5;
	cout << "Test if the stack s5 is empty: " << s5.isEmpty() << endl;
	cout << "Test if the stack s6 is empty: " << s6.isEmpty() << endl;
	for (int i = 0; i < 3; i++) {
		cout << "From s5: " << s5.pop() << endl;
	}
	cout << "Test if the stack s5 is empty: " << s5.isEmpty() << endl;
	for (int i = 0; i < 3; i++) {
		cout << "From s6: " << s6.pop() << endl;
	}
	cout << "Test if the stack s6 is empty: " << s6.isEmpty() << endl;
}

void testSelfToSelf()
{
	Stack s7;
	s7.push(7);
	s7.push(14);
	s7.push(21);
	s7.push(28);
	cout << "Pushed 7, 14, 21 on s7" << endl;
	cout << "Assigning s7 to s7" << endl;
	s7 = s7;
	for (int i = 0; i < 4; i++) {
		cout << "From s7: " << s7.pop() << endl;
	}
}
