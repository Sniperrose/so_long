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

typedef struct s_mlx
{
    void    *mlx;
    void    *win;
    // void    *image;
    int     x;
    int     y;

}              t_mlx;

typedef struct s_img
{
    void    *image;
    int     *widht;
    int     *height;

}              t_img;

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
int ft_validmap(char **map);
int ft_solong(char **map);
void    ft_test();
void    *ft_image();
void    *ft_sosoolong(char **map);

#endif