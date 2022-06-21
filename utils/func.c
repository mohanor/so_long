/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:02:11 by matef             #+#    #+#             */
/*   Updated: 2022/06/21 17:15:46 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
