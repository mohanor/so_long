#include "../so_long.h"

int	ft_strlen(char *p)
{
	int	i;

	i = 0;
	if (!p)
		return (0);
	while (p[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

void	own_exit(char *msg)
{
	ft_putstr(msg);
	exit (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}