/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:40:59 by matef             #+#    #+#             */
/*   Updated: 2022/06/21 22:20:47 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == '0')
		mlx_put_image_to_window(vars->mlx,
			vars->win, vars->ground, j * 50, i * 50);
	if (vars->map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx,
			vars->win, vars->wall, j * 50, i * 50);
	if (vars->map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx,
			vars->win, vars->wall, j * 50, i * 50);
	if (vars->map[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx,
			vars->win, vars->collectible, j * 50, i * 50);
	if (vars->map[i][j] == 'P')
		mlx_put_image_to_window(vars->mlx,
			vars->win, vars->plyer, j * 50, i * 50);
	if (vars->map[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx,
			vars->win, vars->exit, j * 50, i * 50);
}

void	open_win(t_vars *vars)
{
	int	i;
	int	j;

	vars->win = mlx_new_window(vars->mlx,
			vars->map_width * 50, vars->map_height * 50, "so long");
	i = 0;
	while (i < vars->map_height)
	{
		j = 0;
		while (j < vars->map_width)
		{
			put_img(vars, i, j);
			j++;
		}
		i++;
	}
}

void	map_test_func(t_vars *vars, char **map, int i, int j)
{
	if (map[0][j] != '1' || map[i][0] != '1' || \
		map[vars->map_height - 1][j] != '1' \
		|| map[i][vars->map_width - 1] != '1')
		own_exit("map error\n");
	if (map[i][j] == 'C')
		vars->coin++;
	if (map[i][j] == 'P')
	{
		vars->plyer_pos_1 = i;
		vars->plyer_pos_2 = j;
		vars->p++;
	}
	if (map[i][j] == 'E')
		vars->e++;
	if (!(map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'C' \
		|| map[i][j] == 'P' || map[i][j] == 'E'))
		own_exit("map error\n");
}

void	test_map(t_vars *vars)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = vars->map;
	vars->coin = 0;
	map_dimantion(vars);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			map_test_func(vars, map, i, j);
			j++;
		}
		i++;
	}
	if (vars->e == 0 || vars->coin == 0 || vars->p != 1)
		own_exit("map error\n");
}

int	if_possible_to_move(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == 'E' && vars->coin == 0)
		own_exit("success");
	if (vars->map[i][j] == 'E')
		return (0);
	if (vars->map[i][j] != '1' || vars->map[i][j] == 'P')
		return (1);
	return (0);
}
