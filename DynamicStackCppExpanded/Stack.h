#pragma once
#include <stdio.h>

#define GROWTH_FACTOR 2

class Stack {
  public:
	Stack();
	Stack(const Stack& s);
	Stack& operator=(const Stack& s);
	void push(int);
	int pop();
	bool isEmpty();
	~Stack();

  private:
	void manageMemory();
	size_t top;
	size_t size;
	int* data;
};
