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

void    init_var(t_vars *vars, int fd, char *tr)
{
    vars->mlx = mlx_init();
    vars->map = ft_split(read_map(fd, tr), '\n');
    vars->i = 0;
    vars->j = 0;
}

void    map_dimantion(t_vars *vars)
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

void    test_map(t_vars *vars)
{
    int     i;
    int     j;
    char    **map;

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

void    open_win(t_vars *vars)
{
    int i;
    int j;

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

int     if_possible_to_move(t_vars *vars, int i, int j)
{
    if (vars->map[i][j] == 'E' && vars->coin == 0){
        own_exit("success");
    }
    if (vars->map[i][j] == 'E')
        return 0;
    if (vars->map[i][j] != '1' || vars->map[i][j] == 'P')
        return (1);
    return (0);
}

void    if_coin(t_vars *vars)
{
    if (vars->map[vars->plyer_pos_1][vars->plyer_pos_2] == 'C')
    {
        vars->map[vars->plyer_pos_1][vars->plyer_pos_2] = '0';
        vars->coin--;
    }
}

void    move_to(int keycode)
{
    if (keycode == 13)
        ft_putstr("move to top\n");
    if (keycode == 0)
        ft_putstr("move to left\n");
    if (keycode == 1)
        ft_putstr("move to bottom\n");
    if (keycode == 2)
        ft_putstr("move to rgiht\n");
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

int main()
{
    int		fd;
	char	tr[9999];
	t_vars	vars;

    fd = open("./maps/map.ber", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("errror fd\n");
		return (0);
	}

    init_var(&vars, fd, tr);
    test_map(&vars);
    open_win(&vars);

    mlx_hook(vars.win, 2, 0, key_hook, &vars);
    mlx_loop(vars.mlx);
    return (0);
}