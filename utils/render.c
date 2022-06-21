#include "../so_long.h"

void	open_win(t_vars *vars)
{
	int	i;
	int	j;

	vars->win = mlx_new_window(vars->mlx, vars->map_width * 50, vars->map_height * 50, "so long");
	vars->ground = mlx_xpm_file_to_image(vars->mlx, "./img/ground.xpm", &vars->i, &vars->j);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "./img/wall.xpm", &vars->i, &vars->j);
	vars->plyer = mlx_xpm_file_to_image(vars->mlx, "./img/plyer.xpm", &vars->i, &vars->j);
	vars->collectible = mlx_xpm_file_to_image(vars->mlx, "./img/coin.xpm", &vars->i, &vars->j);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "./img/exit.xpm", &vars->i, &vars->j);
	i = 0;
	while (i < vars->map_height)
	{
		j = 0;
		while(j < vars->map_width)
		{
			if (vars->map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->ground, j * 50, i * 50);
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, j * 50, i * 50);
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, j * 50, i * 50);
			if (vars->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->collectible, j * 50, i * 50);
			if (vars->map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->plyer, j * 50, i * 50);
			if (vars->map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, j * 50, i * 50);
			j++;
		}
		i++;
	}
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
		while(map[i][j])
		{
			if (map[0][j] != '1' || map[i][0] != '1' || map[vars->map_height - 1][j] != '1' || map[i][vars->map_width - 1] != '1')
				own_exit("map error\n");
			if (map[i][j] == 'C')
				vars->coin++;
			if (map[i][j] == 'P')
			{
				vars->plyer_pos_1 = i;
				vars->plyer_pos_2 = j;
			}
			j++;
		}
		i++;
	}
}

void	map_dimantion(t_vars *vars)
{
	int i;
	int j;

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

int	if_possible_to_move(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == 'E' && vars->coin == 0)
		own_exit("success");
	if (vars->map[i][j] == 'E')
		return 0;
	if (vars->map[i][j] != '1' || vars->map[i][j] == 'P')
		return (1);
	return (0);
}