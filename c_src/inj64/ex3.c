#include <stdio.h>
/* not sure whether needed; better safe than sorry. */
#include <stdint.h>

void function(int a, int b, int c)
{
	char buffer1[5];
	uintptr_t *ret;

	/*   WORDSIZE (buffer)
	*  + WORDSIZE (backup)
	*  + WORDSIZE (sbp)
	*/
	ret = (uintptr_t *)(&buffer1[0] + 24);
	/* 64-bit code is different, we need 7 here */
	(*ret) += 7;
}

int main()
{
	int x;

	x = 0;
	function(1,2,3);
	x = 1;
	printf("%d\n",x);
	return 0;
}
