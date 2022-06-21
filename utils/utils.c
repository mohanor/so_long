/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matef <matef@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:48:30 by matef             #+#    #+#             */
/*   Updated: 2022/06/21 17:46:57 by matef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	put_new_position(t_vars *vars, int p2, int p1, int keycode)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->ground, vars->plyer_pos_2 * 50, vars->plyer_pos_1 * 50);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->plyer, p2 * 50, p1 * 50);
	if_coin(vars);
	move_to(keycode);
	vars->plyer_pos_2 = p2;
	vars->plyer_pos_1 = p1;
}

int	key_hook(int keycode, t_vars *vars)
{
	int	p1;
	int	p2;

	p1 = vars->plyer_pos_1;
	p2 = vars->plyer_pos_2;
	if (keycode == 2 && if_possible_to_move(vars,
			vars->plyer_pos_1, vars->plyer_pos_2 + 1))
		put_new_position(vars, ++p2, p1, keycode);
	if (keycode == 1 && if_possible_to_move(vars,
			vars->plyer_pos_1 + 1, vars->plyer_pos_2))
		put_new_position(vars, p2, ++p1, keycode);
	if (keycode == 13 && if_possible_to_move(vars,
			vars->plyer_pos_1 - 1, vars->plyer_pos_2))
		put_new_position(vars, p2, --p1, keycode);
	if (keycode == 0 && if_possible_to_move(vars,
			vars->plyer_pos_1, vars->plyer_pos_2 - 1))
		put_new_position(vars, --p2, p1, keycode);
	return (0);
}
