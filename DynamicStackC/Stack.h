#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>

#define GROW_FACTOR 2

typedef struct Stack {
	size_t maxCapacity;
	size_t top;
	int* data;
} Stack;

void init(Stack*);
void destroy(Stack*);
void push(Stack*, int);
int pop(Stack*);
bool isEmpty(Stack*);
void manageMemory(Stack*);

#endif
