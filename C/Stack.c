#include <stdio.h>
#include <stdbool.h>
#include "Stack.h"

Stack NewStack()
{
	Stack s = {NULL, -1};
	return s;
}

void push(Stack *self, int command)
{
	int *arr = self->arr;
	self->top++;
	if (arr == NULL)
	{
		arr = (int *)malloc(sizeof(int) + 1);
	}
	else
	{
		arr = (int *)realloc(arr, sizeof(int) * (self->top + 1));
	}
	if (arr != NULL)
		arr[self->top] = command;
	self->arr = arr;
}

char pop(Stack *self)
{
	if (self->top == -1)
	{
		printf("Empty");
		return NULL;
	}
	else
		return self->arr[self->top--];
}

char peek(Stack *self)
{
	if (self->top == -1)
	{
		printf("Empty");
		return;
	}
	else
		return self->arr[self->top];
}

void empty(Stack *self)
{
	free(self->arr);
	self->arr = NULL;
	self->top = -1;
}

void show(Stack *self)
{
	if (self->top == -1)
	{
		printf("\nUnderflow!!");
	}
	else
	{
		printf("\nElements present in the stack: \n");
		for (int i = self->top; i >= 0; --i)
			printf("%c\n", self->arr[i]);
	}
}