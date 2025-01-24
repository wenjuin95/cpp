#include <stdio.h>

void eat(char *name, char *food)
{
	printf("%s eats %s\n", name, food);
}

int main()
{
	eat("john", "apple");
}