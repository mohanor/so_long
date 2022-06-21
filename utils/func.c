/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:02:11 by matef             #+#    #+#             */
/*   Updated: 2022/06/21 19:30:04 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
/*
int	has_empty_line(t_vars *vars)
{
	return (1);
}
*/
void	map_dimantion(t_vars *vars)
{
	int	i;
	int	j;

	i = ft_strlen(vars->map[0]);
	j = 0;
	while (vars->map[j])
	{
		if (i != ft_strlen(vars->map[j]))
			own_exit("map dimantion not correct\n");
		j++;
	}
	vars->map_width = i;
	vars->map_height = j;
}

void	own_exit(char *msg)
{
	ft_putstr(msg);
	exit (0);
}

int	exit_2(t_vars *vars)
{
	ft_putstr("you out\n");
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
}

void	empty_line(char *tr)
{
	int	k;

	k = 0;
	if (tr[0] == '\n')
		own_exit("map has empty line\n");
	while (tr[k])
	{
		if ((tr[k] == tr[k + 1] && tr[k] == '\n') \
				|| (tr[k] == '\n' && tr[k + 1] == '\0'))
			own_exit("map has empty line\n");
		k++;
	}
}
