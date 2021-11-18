#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


void Saludar(int a, int b);
void Despedir(int a, int b);

int main()
{
	setbuf(stdout, NULL);


	void(*pFunc)(int a, int b);

	pFunc= Saludar;
	pFunc(10, 5);
	pFunc=Despedir;
	pFunc(10,5);

	return 0;
}




void Saludar(int a, int b)
{
	printf("SUMA: %d\n", a+b);
}




void Despedir(int a, int b)
{
	printf("RESTA: %d\n", a-b);
}
