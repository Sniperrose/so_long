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

#define res 64

typedef struct s_vector
{
    int x;
    int y;
}              t_vector;

typedef struct s_image
{
    void        *pointer;
    t_vector    size;
    char        *pixels;
    int         bits_pp;
    int         line_size;
    int         endian;
}               t_image;

typedef struct s_icon
{
    t_image wall;
    t_image space;
    t_image coll;
    t_image exit;
    t_image player;
    t_image end1;
    t_image end2;
    t_image end3;
}              t_icon;

typedef struct s_game
{
    void    *ptr;
    void    *win;
    char    **map;
    int     x;
    int     y;
    int     collectible;
    int     type;
}              t_game;

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
int ft_validpath(char **map, int col);

t_image	ft_new_sprite(void *ptr, char *path);
t_vector get_pos_player(char **map);

int    ft_do_move(t_game *game, t_vector pos, char dir);
int can_i_move_right(t_game *game, t_vector pos);
int can_i_move_left(t_game *game, t_vector pos);
int can_i_move_up(t_game *game, t_vector pos);
int can_i_move_down(t_game *game, t_vector pos);

void	*put_img(t_icon show, char c);
void    *solong(t_game mlx);
void    *ft_drawgame(t_game game, char **map);
void    *display_game(t_game    *game, int i);


void    ft_bzero(int *nbr, int size);
int ft_mapcheck(char **map);
int ft_wallcheck(char **map, int i, size_t x);
int ft_comptcheck(char **map, int i, int j);

#endif