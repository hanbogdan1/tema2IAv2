#include <iostream>
#include "cls.h"

int main()
{
	cls a;
	a.dfs(a.initial_values);
	a.gbfs(a.initial_values);

	return 0;
}
