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
    vars->cl = mlx_xpm_file_to_image(vars->mlx, "./img/coin.xpm", &vars->i, &vars->j);

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
                mlx_put_image_to_window(vars->mlx, vars->win, vars->cl, j * 50, i * 50);
            if (vars->map[i][j] == 'P')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->plyer, j * 50, i * 50);
            j++;
        }
        i++;
    }
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

    printf("width %d\n", vars.map_width);
    printf("height %d\n", vars.map_height);
    printf("coin %d\n", vars.coin);
    printf("player i %d : j %d\n", vars.plyer_pos_1, vars.plyer_pos_2);
    mlx_loop(vars.mlx);
    return (0);
}