#include <errno.h>
#include <stdio.h>

void	function_test(void)
{
	printf("in: %d\n", errno);
	errno = 3;
}
