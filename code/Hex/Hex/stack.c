#include "stack.h"
#include <stdlib.h>

Stack* stack_create() {
	return NULL;
}

bool stack_empty(Stack* s) {
	return s == NULL;
}

Stack* stack_add(Stack* s, int val) {
	Stack* new = malloc(sizeof(Stack));
	if (new == NULL)
		return NULL;
	new->val = val;
	if (s == NULL)
		new->size = 1;
	else
		new->size = s->size + 1;
	new->prev = s;
	return new;
}

Stack* stack_pop(Stack* s) {
	if (s == NULL)
		return NULL;
	Stack* n = s->prev;
	free(s);
	return n;
}

int stack_peek(Stack* s) {
	return s->val;
}