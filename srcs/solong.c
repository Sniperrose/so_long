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

void	*ft_endgame(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (game->map[i + 1] != NULL)
	{
		j = 1;
		while (game->map[i][j + 1] != '\0')
		{
			game->map[i][j] = '0';
			j++;
		}
		i++;
	}
	i = (int)ft_splitsize(game->map) / 2;
	j = (int)ft_strlen(game->map[0]) / 2;
	game->map[i][j - 1] = 'e';
	game->map[i][j] = 'n';
	game->map[i][j + 1] = 'd';
	return (NULL);
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
	else if (keysym == XK_Escape)
	{
		ft_free(game->map, ft_splitsize(game->map));
		if (!game->ptr)
			free(game->ptr);
		ft_putstr_fd("Exit: ESC\n", 1);
		exit (0);
	}
	if (i == -1)
		ft_endgame(game);
	display_game(game, game->type);
	return (0);
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
	if (!game.collectible)
		return (NULL);
	game.moves = 1;
	game.type = 0;
	game.x = ((int)ft_strlen(game.map[0])) * res;
	game.y = ((int)ft_splitsize(game.map)) * res;
	game.ptr = mlx_init();
	game.win = mlx_new_window(game.ptr, game.x, game.y, "so_long_test");
	display_game(&game, game.type);
	mlx_hook(game.win, 17, 1L << 19, handle_key, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_loop(game.ptr);
	return (game.ptr);
}
