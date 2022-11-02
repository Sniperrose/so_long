/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:57:58 by galtange          #+#    #+#             */
/*   Updated: 2022/11/01 15:48:51 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_endgame(t_game *game, char *str)
{
	ft_free(game->map, ft_splitsize(game->map));
	ft_freeimgs(game);
	mlx_destroy_window (game->ptr, game->win);
	mlx_destroy_display (game->ptr);
	free(game->ptr);
	ft_putstr_fd(str, 1);
	return (0);
}

int	handle_key(t_game *game)
{
	exit (ft_endgame(game, "Exit: RED CROSS\n"));
}

void	*ft_won(t_game *game)
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
	return (game->ptr);
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
	{
		usleep(1000);
		exit (ft_endgame(game, "Exit: Game end ^.^\n"));
	}
	display_game(game, game->type);
	return (0);
}

int	solong(t_game game)
{
	game.collectible = ft_mapcheck(game.map);
	if (!game.collectible || !ft_check_imgpaths())
		return (0);
	game.moves = 1;
	game.type = 0;
	game.x = ((int)ft_strlen(game.map[0])) * RES;
	game.y = ((int)ft_splitsize(game.map)) * RES;
	game.ptr = mlx_init();
	if (!game.ptr)
		return (0);
	game.win = mlx_new_window(game.ptr, game.x, game.y, "so_long_test");
	if (!game.win)
		return (0);
	if (!ft_getimgs(&game))
		return (0);
	display_game(&game, game.type);
	mlx_hook(game.win, KeyPress, KeyPressMask, &handle_keypress, &game);
	mlx_hook(game.win, 17, 1L << 19, &handle_key, &game);
	mlx_loop(game.ptr);
	return (1);
}
