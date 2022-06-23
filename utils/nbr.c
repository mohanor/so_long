/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 23:02:49 by matef             #+#    #+#             */
/*   Updated: 2022/06/21 23:03:15 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putnbr(int n)
{
	long long	k;

	k = n;
	if (k >= 10)
		ft_putnbr(k / 10);
	ft_putchar(k % 10 + 48);
}

char	*ft_map_size(char *str)
{
	int		fd;
	int		b;
	int		size;
	char	*ptr;

	b = 1;
	size = 0;
	fd = open(str, O_RDONLY);
	while (b != 0)
	{
		b = read(fd, &str, 1);
		if (b == -1)
			return (0);
		if (b != 0)
			size++;
	}
	ptr = (char *)malloc(size * sizeof(char));
	close (fd);
	return (ptr);
}
