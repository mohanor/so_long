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

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 2 && if_possible_to_move(vars, vars->plyer_pos_1, vars->plyer_pos_2 + 1)){
		mlx_put_image_to_window(vars->mlx, vars->win, vars->ground, vars->plyer_pos_2 * 50, vars->plyer_pos_1 * 50);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->plyer, ++vars->plyer_pos_2 * 50, vars->plyer_pos_1 * 50);
		if_coin(vars);
	}
	if (keycode == 1 && if_possible_to_move(vars, vars->plyer_pos_1 + 1, vars->plyer_pos_2)){
		mlx_put_image_to_window(vars->mlx, vars->win, vars->ground, vars->plyer_pos_2 * 50, vars->plyer_pos_1 * 50);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->plyer, vars->plyer_pos_2 * 50, ++vars->plyer_pos_1 * 50);
		if_coin(vars);
	}
    if (keycode == 13 && if_possible_to_move(vars, vars->plyer_pos_1 - 1, vars->plyer_pos_2)){
        mlx_put_image_to_window(vars->mlx, vars->win, vars->ground, vars->plyer_pos_2 * 50, vars->plyer_pos_1 * 50);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->plyer, vars->plyer_pos_2 * 50, --vars->plyer_pos_1 * 50);
        if_coin(vars);
    }
    if (keycode == 0 && if_possible_to_move(vars, vars->plyer_pos_1, vars->plyer_pos_2 - 1)){
        mlx_put_image_to_window(vars->mlx, vars->win, vars->ground, vars->plyer_pos_2 * 50, vars->plyer_pos_1 * 50);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->plyer, --vars->plyer_pos_2 * 50, vars->plyer_pos_1 * 50);
        if_coin(vars);
    }
    move_to(keycode);
    return 0;
}