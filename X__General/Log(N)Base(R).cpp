#include<stdio.h>
unsigned	int	Logn(unsigned	int	n,	unsigned	int	r)
{
			return	(n	>	r-1)?	1	+	Logn(n/r,	r):	0;
}
int	main()
{
		unsigned	int	n	=	256;
		unsigned	int	r	=	4;
		printf("%u",	Logn(n,	r));
		getchar();
		return	0;
}
