#include <unistd.h>

void ft_putchar(char c)
{
	write(1,&c,1);	
}


int  main()
{
	write(1,", \n", 3);
	ft_putchar('test');
	return 0;
}

