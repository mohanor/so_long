/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:39:36 by matef             #+#    #+#             */
/*   Updated: 2022/06/22 09:12:32 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(int fd, char *tr)
{
	char	str;
	int		b;
	int		h;

	b = 1;
	h = 0;
	while (b != 0)
	{
		b = read(fd, &str, 1);
		if (b == -1)
			return (0);
		if (b != 0)
			tr[h++] = str;
		tr[h] = '\0';
	}
	if (h == 0)
		return (0);
	close (fd);
	return (tr);
}

void	init_var(t_vars *vars, int fd, char *tr)
{
	vars->mlx = mlx_init();
	vars->map = ft_split(read_map(fd, tr), '\n');
	empty_line(tr);
	vars->i = 0;
	vars->j = 0;
	vars->move = 0;
	vars->ground = mlx_xpm_file_to_image(vars->mlx,
			"./img/ground.xpm", &vars->i, &vars->j);
	vars->wall = mlx_xpm_file_to_image(vars->mlx,
			"./img/wall.xpm", &vars->i, &vars->j);
	vars->plyer = mlx_xpm_file_to_image(vars->mlx,
			"./img/plyer.xpm", &vars->i, &vars->j);
	vars->collectible = mlx_xpm_file_to_image(vars->mlx,
			"./img/coin.xpm", &vars->i, &vars->j);
	vars->exit = mlx_xpm_file_to_image(vars->mlx,
			"./img/exit.xpm", &vars->i, &vars->j);
	vars->e = 0;
	vars->p = 0;
}

void	if_coin(t_vars *vars)
{
	if (vars->map[vars->plyer_pos_1][vars->plyer_pos_2] == 'C')
	{
		vars->map[vars->plyer_pos_1][vars->plyer_pos_2] = '0';
		vars->coin--;
	}
}

void	move_to(t_vars *vars)
{
	ft_putstr("moves : ");
	ft_putnbr(++vars->move);
	ft_putchar('\n');
}

int	main(int ac, char **av)
{
	int		fd;
	char	*tr;	
	t_vars	vars;

	if (ac != 2)
		return (0);
	check_file_type(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("errror fd\n");
		return (0);
	}
	tr = ft_map_size(av[1]);
	if (!tr)
		return (0);
	init_var(&vars, fd, tr);
	test_map(&vars);
	open_win(&vars);
	mlx_hook(vars.win, 2, 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_2, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
