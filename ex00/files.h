
#include <unistd.h>
#include <stdlib.h>

int filcell(int **num, int pos);
int fillcell_rev(int **num, int pos);
int ft_strcmp(int *s1, int *s2);
int ft_sdkcmp(int **num, int **num2);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
