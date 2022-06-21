#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
#include <stdio.h>
typedef struct s_vars{
    void    *mlx;
    void    *win;
    char    **map;
    void    *ground;
    void    *wall;
    void    *plyer;
    void    *collectible;
    void    *exit;
    int     plyer_pos_1;
    int     plyer_pos_2;
    int     map_width;
    int     map_height;
    int     coin;
    int     i;
    int     j;
} t_vars;

int	ft_strlen(char *p);
void	ft_putstr(char *s);
void	own_exit(char *msg);
void	ft_putchar(char c);
char	**ft_split(char const *s, char c);
int	key_hook(int keycode, t_vars *vars);
void    if_coin(t_vars *vars);
int	if_possible_to_move(t_vars *vars, int i, int j);
void	move_to(int keycode);
void	open_win(t_vars *vars);
void	test_map(t_vars *vars);
void	map_dimantion(t_vars *vars);
int	if_possible_to_move(t_vars *vars, int i, int j);


#endif