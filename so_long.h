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
    void    *cl;
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

#endif