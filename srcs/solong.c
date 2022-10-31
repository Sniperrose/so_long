/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:57:58 by galtange          #+#    #+#             */
/*   Updated: 2022/10/30 22:05:56 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int ft_endgame(t_game *game, char *str)
{
	ft_free(game->map, ft_splitsize(game->map));
	mlx_destroy_window(game->ptr, game->win);
	ft_putstr_fd(str, 1);
	return (0);
}

int	handle_keypress(int keysym, t_game *game)
{
	t_vector	pos;
	int			i;

	i = 0;
	pos = get_pos_player(game->map);
	if (keysym == XK_d || keysym == XK_D)
		i = can_i_move_right(game, pos);
	else if (keysym == XK_W || keysym == XK_w)
		i = can_i_move_up(game, pos);
	else if (keysym == XK_A || keysym == XK_a)
		i = can_i_move_left(game, pos);
	else if (keysym == XK_S || keysym == XK_s)
		i = can_i_move_down(game, pos);
	if (keysym == XK_Escape)
		exit (ft_endgame(game, "Exit: ESC\n"));
	if (i == -1)
		exit (ft_endgame(game, "Exit: Game end ^.^\n"));
	display_game(game, game->type);
	return (0);
}


int	ft_check_imgpaths()
{
	int	fd[13];
	int	i;
	
	fd[0] = open("imgs/E.xpm",O_RDONLY);
	fd[1] = open("imgs/0.xpm",O_RDONLY);
	fd[2] = open("imgs/1.xpm",O_RDONLY);
	fd[3] = open("imgs/10.xpm",O_RDONLY);
	fd[4] = open("imgs/11.xpm",O_RDONLY);
	fd[5] = open("imgs/20.xpm",O_RDONLY);
	fd[6] = open("imgs/21.xpm",O_RDONLY);
	fd[7] = open("imgs/30.xpm",O_RDONLY);
	fd[8] = open("imgs/31.xpm",O_RDONLY);
	fd[9] = open("imgs/40.xpm",O_RDONLY);
	fd[10] = open("imgs/41.xpm",O_RDONLY);
	fd[11] = open("imgs/C.xpm",O_RDONLY);
	i = -1;
	while (++i < 12)
	{	
		close (fd[i]);
		if (fd[i] < 0)
			return (ft_error("Please check the image paths!\n"));
	}
	return (1);
}

int	handle_key(int status, t_game *game)
{
	(void)status;
	(void)game;
	ft_putstr_fd("Exit: closed\n", 1);
	exit (0);
	return (0);
}

void	*solong(t_game game)
{
	game.collectible = ft_mapcheck(game.map);
	if (!game.collectible || !ft_check_imgpaths())
		return (0);
	game.moves = 1;
	game.type = 0;
	game.x = ((int)ft_strlen(game.map[0])) * res;
	game.y = ((int)ft_splitsize(game.map)) * res;
	game.ptr = mlx_init();
	if (!game.ptr)
		return (NULL);
	game.win = mlx_new_window(game.ptr, game.x, game.y, "so_long_test");
	if (!game.win)
		return (NULL);
	if (!ft_getimgs(&game))
		return (NULL);
	display_game(&game, game.type);
	mlx_hook(game.win, 17, 1L << 19, handle_key, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_loop(game.ptr);
	return (game.ptr);
}
