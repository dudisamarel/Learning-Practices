#include "Stack.h"
#include <stdio.h>
#include <stdbool.h>

int reverseCommand(char command, int number)
{
	switch (command)
	{
	case '+':
		return number -= 1;
	case '-':
		return number += 1;
	case '*':
		return number /= 2;
	case '/':
		return number *= 2;
	}
}

int main()
{
	Stack s = NewStack();

	int initNumber, number;
	char command;
	printf("Enter your number ");
	scanf_s("%d", &initNumber);
	number = initNumber;

	printf("Enter your command ");
	scanf_s(" %c", &command, 1);

	while (command != 'e')
	{
		switch (command)
		{
		case '+':
			number++;
			push(&s, command);
			break;
		case '-':
			number--;
			push(&s, command);
			break;
		case '*':
			number *= 2;
			push(&s, command);
			break;
		case '/':
			number /= 2;
			push(&s, command);
			break;
		case 'u':
			number = reverseCommand(pop(&s), number);
			break;
		case 'r':
			printf("Last command is %c \nThe number is %d\n", peek(&s), number);
			break;
		case 'c':
			empty(&s);
			number = initNumber;
			break;
		default:
			break;
		}
		printf("Enter your command ");
		scanf_s(" %c", &command, 1);
	}
	return 0;
}
