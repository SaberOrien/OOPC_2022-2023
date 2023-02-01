#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
	this->top = 0;
	this->maxCapacity = 1;
	this->data = (int*)malloc(this->maxCapacity * sizeof(int));
	if (this->data == NULL) {
		cout << "Error initializing. Aborting" << endl;
		abort();
	}
}

Stack::~Stack()
{
	free(this->data);
}

bool Stack::isEmpty()
{
	return this->top == 0;
}

void Stack::push(int element)
{
	manageMemory();
	this->data[this->top++] = element;
}

void Stack::manageMemory()
{
	if (this->top >= this->maxCapacity) {
		size_t newSize;
		int* newData;

		if (this->maxCapacity == 0) {
			newSize = 1;
		}
		else {
			newSize = this->maxCapacity + GROWTH_FACTOR;
		}

		if (newSize >= (((size_t)-1) - GROWTH_FACTOR) / sizeof(int)) {
			cout << "Not enough memory, aborting.\n" << endl;
			abort();
		}

		newData = (int*)realloc(this->data, newSize * sizeof(int));
		if (!newData) {
			cout << "Unsuccessful expansion. Aborting\n" << endl;
			abort();
		}
		cout << "Stack expansion: " << this->maxCapacity << " -> " << newSize << endl;
		this->data = newData;
		this->maxCapacity = newSize;
	}
}

int Stack::pop()
{
	if (isEmpty()) {
		cout << "Popping from an empty stack.\n" << endl;
		abort();
	}
	return this->data[--(this->top)];
}
