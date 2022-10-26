#ifndef SO_LONG_H
#define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>  
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
#include <X11/keysym.h>

typedef struct s_game
{
    void    *ptr;
    void    *win;
    char    **map;
    void    *win2;

    int     win_x;
    int     win_y;
    int     collectible;
    int     player_x;
    int     player_y;
}              t_game;

typedef struct s_image
{
    void    *img;
    int     *widht;
    int     *heigth;
}               t_image;

int main(int ac, char **av);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *c);
void	ft_putstr_fd(char *s, int fd);
char    *ft_strjoin(char *all, char const *argv);
size_t	ft_count(const char *all, char sep);
void	ft_split2(char **result, char const *all, char sep, size_t size);
void	ft_free(char **ptr, size_t line);
char	*get_next_line(int fd);
char    **ft_readmap(int fd);
int ft_error(char *str);
size_t	ft_splitsize(char **str);

void    *ft_image();

void    *solong(t_game mlx);

void    ft_bzero(int *nbr, int size);
int ft_mapcheck(char **map);
int ft_wallcheck(char **map, int i, size_t x);
int ft_comptcheck(char **map, int i, int j);



// int ft_solong(char **map);
// void    ft_test();
// void    *ft_image();
// void    *ft_sosoolong(char **map);

#endif