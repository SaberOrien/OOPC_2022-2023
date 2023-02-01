#include "Stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void init(Stack*);
void destroy(Stack*);
void push(Stack*, int);
int pop(Stack*);
bool isEmpty(Stack*);
void manageMemory(Stack*);

void init(Stack* s)
{
	s->top = 0;
	s->maxCapacity = 1;
	s->data = malloc(s->maxCapacity * sizeof(int));
	if (s->data == NULL) {
		printf("Error initializing. Aborting\n");
		abort();
	}
}

void destroy(Stack* s)
{
	free(s->data);
}

void push(Stack* s, int element)
{
	manageMemory(s);
	s->data[s->top++] = element;
}

void manageMemory(Stack* s)
{
	if (s->top >= s->maxCapacity) {
		int* newData;
		size_t newSize = 0;
		if (s->maxCapacity == 0) {
			newSize = 1;
		}
		else {
			newSize = s->maxCapacity + GROW_FACTOR;
		}
		if (newSize >= (((size_t)-1) - GROW_FACTOR) / sizeof(int)) {
			printf("Not enough memory, aborting.\n");
			free(s->data);
			abort();
		}
		newData = realloc(s->data, newSize * sizeof(int));
		if (newData == NULL) {
			free(s->data);
			abort();
		}
		printf("Changing stack size: %ld -> %ld\n", s->maxCapacity, newSize);
		s->data = newData;
		s->maxCapacity = newSize;
	}
}

int pop(Stack* s)
{
	if (isEmpty(s) == true) {
		printf("\nTrying to pop from an empty stack.\n\nAborting\n\n");
		destroy(s);
		abort();
	}
	return s->data[--(s->top)];
}

bool isEmpty(Stack* s)
{
	return s->top == 0;
}
