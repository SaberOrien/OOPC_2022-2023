#include "Stack.h"
#include <stdbool.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	Stack stack1, stack2;
	Stack* s1 = &stack1;
	Stack* s2 = &stack2;
	init(s1);
	init(s2);
	printf("Testing the stacks: s1\ts2.\n");
	printf("Test if the first stack is empty: %s\n", isEmpty(s1)? "true" : "false");
	printf("Test if the second stack is empty: %s\n", isEmpty(s2)? "true" : "false");
	for (int i = 0; i < 3; i++){
		push(s1, i);
		printf("Pushing %d on s1\n", i);
	}
	printf("\nTest if the first stack is empty: %s\n", isEmpty(s1)? "true" : "false");
	for (int i = 0; i < 5; i++){
		push(s2, i+2);
		printf("Pushing %d on s2\n", i+2);
	}
	for (int i = 0; i < 3; i++){
		printf("Popping from s1: %d\n", pop(s1));
	}
	printf("\nTest if the first stack is empty: %s\n", isEmpty(s1)? "true" : "false");
	for (int i = 0; i < 4; i++){
		printf("Popping from s2: %d\n", pop(s2));
	}
	printf("\nTest if the second stack is empty: %s\n", isEmpty(s2)? "true" : "false");
	printf("Popping from s2: %d", pop(s2));
	printf("\nTest if the second stack is empty: %s\n", isEmpty(s2)? "true" : "false");
	destroy(s1);
	destroy(s2);
	return 0;
}
