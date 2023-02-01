#pragma once
#include <stdio.h>

#define GROWTH_FACTOR 2

class Stack {
  public:
	Stack();
	void push(int);
	int pop();
	bool isEmpty();
	~Stack();

  private:
	void manageMemory();
	size_t top;
	size_t maxCapacity;
	int* data;
};
