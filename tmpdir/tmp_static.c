#include "tmp.h"

void	static_test(void)
{
	static int	si;

	printf("si = %d\n", ++si);
	return ;
}

int	main(void)
{
	static_test();
	static_test();
	static_test();
}
