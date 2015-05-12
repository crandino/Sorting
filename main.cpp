#include "DynArray.h"
#include <stdio.h>
#include <random>
#include <time.h>

int main(int argc, char **argv)
{
	DynArray<int> d_no_opt(100);
	DynArray<int> d_opt(100);
	DynArray<int> d_super_opt(100);

	srand(time(NULL));

	for (unsigned int i = 0; i < 10000; i++)
	{
		d_no_opt.pushBack(rand());
	}

	for (unsigned int i = 0; i < 10000; i++)
	{
		d_opt.pushBack(rand());
	}

	for (unsigned int i = 0; i < 10000; i++)
	{
		d_super_opt.pushBack(rand());
	}

	printf("%d\n", d_no_opt.sort());
	printf("%d\n", d_opt.sort_opt());
	printf("%d\n", d_super_opt.sort_super_opt());
	getchar();

	return 0;
}