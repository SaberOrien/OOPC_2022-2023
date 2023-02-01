#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
	this->top = 0;
	this->size = 0;
	this->data = NULL;
}

Stack::~Stack()
{
	free(this->data);
}

Stack::Stack(const Stack& s)
{
	this->size = s.size;
	this->top = s.top;
	if (size > 0) {
		this->data = (int*)malloc(this->size * sizeof(int));
		if (!(this->data)) {
			cout << "Unsuccessfull copy constructor operation. \nAborting"
				 << endl;
			abort();
		}
	}
	else {
		this->data = NULL;
		abort();
	}
	for (size_t i = 0; i < size; i++) {
		this->data[i] = s.data[i];
	}
}


Stack& Stack::operator=(const Stack& s)
{
	if (this == &s) {
		return *this;
	}
	if (this->size < s.top) {
		free(this->data);
		this->size = s.size;
		this->top = s.top;
		this->data = NULL;
		if (this->size > 0) {
			this->data = (int*)realloc(this->data,this->size * sizeof(int));
			if (!(this->data)) {
				cout << "Unsuccessfull copy constructor operation. \nAborting"
					 << endl;
				abort();
			}
		}
	}
	this->size = s.size;
	this->top = s.top;
	for (size_t i = 0; i < size; i++) {
		this->data[i] = s.data[i];
	}
	return *this;
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
	if (this->top >= this->size) {
		size_t newSize;
		int* newData;

		if (this->size == 0) {
			newSize = GROWTH_FACTOR;
		}
		else {
			newSize = this->size + GROWTH_FACTOR;
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
		cout << "Stack expansion: " << this->size << " -> " << newSize << endl;
		this->data = newData;
		this->size = newSize;
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
