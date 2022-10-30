/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:51:13 by galtange          #+#    #+#             */
/*   Updated: 2022/10/30 21:57:05 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_vector	get_pos_player(char **map)
{
	t_vector	pos;

	pos.y = 0;
	while (map[pos.y] != NULL)
	{
		pos.x = 0;
		while (map[pos.y][pos.x] != '\0')
		{
			if (map[pos.y][pos.x] == 'P' ||
				map[pos.y][pos.x] == 'D')
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return (pos);
}

int	ft_do_move(t_game *game, t_vector pos, char dir)
{
	game->map[pos.y][pos.x] = '0';
	if (dir == 'D')
		game->map[pos.y][pos.x + 1] = 'P';
	else if (dir == 'A')
		game->map[pos.y][pos.x - 1] = 'P';
	else if (dir == 'W')
		game->map[pos.y - 1][pos.x] = 'P';
	else if (dir == 'S')
		game->map[pos.y + 1][pos.x] = 'P';
	ft_putstr_fd(ft_itoa(game->moves++), 1);
	ft_putstr_fd("\n", 1);
	return (1);
}
