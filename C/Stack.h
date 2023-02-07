
typedef struct Stack
{
	int *arr;
	int top;
} Stack;

Stack NewStack();
void push(Stack *self, char command);
char pop(Stack *self);
char peek(Stack *self);
void empty(Stack *self);
void show(Stack *self);