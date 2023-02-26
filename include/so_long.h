/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:17:14 by galtange          #+#    #+#             */
/*   Updated: 2022/11/01 15:58:27 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>  
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define RES 64

typedef struct s_vector
{
	int	x;
	int	y;
}		t_vector;

typedef struct s_image
{
	void		*pointer;
	t_vector	size;
}		t_image;

typedef struct s_icon
{
	t_image	wall;
	t_image	space;
	t_image	coll;
	t_image	exit;
	t_image	player10;
	t_image	player11;
	t_image	player20;
	t_image	player21;
	t_image	player30;
	t_image	player31;
	t_image	player40;
	t_image	player41;
	t_image	trap1;
	t_image	trap2;
	t_image	died;
	t_image	won;
}		t_icon;

typedef struct s_nbr
{
	t_image	n0;
	t_image	n1;
	t_image	n2;
	t_image	n3;
	t_image	n4;
	t_image	n5;
	t_image	n6;
	t_image	n7;
	t_image	n8;
	t_image	n9;
}		t_nbr;

typedef struct s_game
{
	void	*ptr;
	void	*win;
	char	**map;
	int		x;
	int		y;
	int		collectible;
	int		type;
	int		moves;
	t_icon	imgs;
	t_nbr	nbr;
}		t_game;

int			main(int ac, char **av);
char		*ft_itoa(int nb);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *c);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strjoin(char *all, char const *argv);
size_t		ft_count(const char *all, char sep);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_substr2(char const *s, unsigned int start, size_t len);
void		ft_split2(char **result, char const *all, char sep, size_t size);
void		ft_free(char **ptr, size_t line);
char		*get_next_line(int fd);
char		**ft_readmap(int fd);
int			ft_error(char *str);
int			ft_end_error(int fd, t_game *g);
int			ft_extmap(char *str);
int			ft_check_imgpaths(int i);
size_t		ft_splitsize(char **str);
int			ft_validp(char **map, int size);
t_image		ft_new_image(void *ptr, int width, int height);
t_image		ft_new_sprite(void *ptr, char *path);
void		ft_putnbr_fd(int n, int fd);
int			ft_getimgs(t_game *game);
int			ft_freeimgs(t_game *game);
int			ft_freeimgs2(t_game *game);
t_icon		ft_readimgs(void *ptr);
t_image		ft_new_sprite(void *ptr, char *path);
t_vector	get_pos_player(char **map);
int			ft_do_move(t_game *game, t_vector pos, char dir);
int			can_i_move_right(t_game *game, t_vector pos);
int			ft_do_die(t_game *game, t_vector pos, char dir);
int			ft_find_player(char **map);
int			ft_do_end(t_game *game, t_vector pos, char dir);
int			can_i_move_left(t_game *game, t_vector pos);
int			can_i_move_up(t_game *game, t_vector pos);
int			can_i_move_down(t_game *game, t_vector pos);
void		*put_img(t_icon show, char c);
int			solong(t_game mlx);
void		*display_game(t_game *game, int i);
void		ft_bzero(int *nbr, int size);
int			ft_mapcheck(char **map);
int			ft_wallcheck(char **map, int i, size_t x);
int			ft_comptcheck(char **map, int i, int j);
int			ft_endgame(t_game *game, char *str);
int			ft_err(t_game *game, char *str);
int			ft_win_err(t_game *game);
int			ft_image_err(t_game *game);
void		*display_moves(t_game *game, int moves);
int			ft_getnbrs(t_game *game);
int			ft_freenbrs(t_game *game);

#endif
