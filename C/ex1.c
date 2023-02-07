#include <stdio.h>
#include <stdbool.h>

void ex1()
{
	bool x = true;
	char input;
	int number = 0;
	while (x)
	{
		printf("Enter your char ");
		scanf_s(" %c", &input, 1);
		if (input >= '0' && input <= '9')
		{
			number = input - '0';
			continue;
		}
		else if (input >= 'A' && input <= 'Z')
		{
			printf("The value is %c \n", input + 32);
			continue;
		}
		else
		{
			if (input >= 'a' && input <= 'z')
			{
				int newValue;
				if (number % 3 == 0)
				{
					newValue = input + 3;
				}
				else
				{
					newValue = input - 3;
				}
				if (newValue < 'a')
					newValue += 26;
				if (newValue > 'z')
					newValue -= 26;
				printf("The value is %c \n", newValue);
				continue;
			}
			else
				printf("The value is %c \n", input);
		}
	}

	return 0;
}

int main()
{

	ex1();
	return 0;
}