/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_hor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:22:58 by galtange          #+#    #+#             */
/*   Updated: 2022/10/30 21:55:50 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_left_d(t_game *game, int x, int y)
{
	game->map[y][x] = 'E';
	if (game->map[y][x - 1] == 'C')
	{
		game->collectible -= 1;
		game->map[y][x - 1] = 'P';
		game->type = 40;
	}
	else if (game->map[y][x - 1] == '0')
	{
		game->map[y][x - 1] = 'P';
		game->map[y][x] = 'E';
		game->type = 40;
	}
	ft_putnbr_fd(game->moves++, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

int	can_i_move_left(t_game *game, t_vector pos)
{
	if (game->map[pos.y][pos.x - 1] == '1')
		return (0);
	else if (game->map[pos.y][pos.x] == 'D')
		return (ft_left_d(game, pos.x, pos.y));
	game->type = 40;
	if (game->map[pos.y][pos.x - 1] == '0')
		return (ft_do_move(game, pos, 'A'));
	else if (game->map[pos.y][pos.x - 1] == 'C')
	{
		game->collectible -= 1;
		return (ft_do_move(game, pos, 'A'));
	}
	else if (game->map[pos.y][pos.x - 1] == 'E')
	{
		game->map[pos.y][pos.x] = '0';
		if (game->collectible == 0)
			return (ft_do_end(game, pos, 'A'));
		else
			game->map[pos.y][pos.x - 1] = 'D';
		game->type = 41;
		ft_putnbr_fd(game->moves++, 1);
		ft_putstr_fd("\n", 1);
		return (0);
	}
	return (ft_do_die(game, pos, 'A'));
}

int	ft_right_d(t_game *game, int x, int y)
{
	game->map[y][x] = 'E';
	if (game->map[y][x + 1] == 'C')
	{
		game->collectible -= 1;
		game->map[y][x + 1] = 'P';
		game->type = 20;
	}
	else if (game->map[y][x + 1] == '0')
	{
		game->map[y][x + 1] = 'P';
		game->map[y][x] = 'E';
		game->type = 20;
	}
	ft_putnbr_fd(game->moves++, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

int	can_i_move_right(t_game *game, t_vector pos)
{
	if (game->map[pos.y][pos.x + 1] == '1')
		return (0);
	if (game->map[pos.y][pos.x] == 'D')
		return (ft_right_d(game, pos.x, pos.y));
	game->type = 20;
	if (game->map[pos.y][pos.x + 1] == '0')
		return (ft_do_move(game, pos, 'D'));
	else if (game->map[pos.y][pos.x + 1] == 'C')
	{
		game->collectible -= 1;
		return (ft_do_move(game, pos, 'D'));
	}
	else if (game->map[pos.y][pos.x + 1] == 'E')
	{
		game->map[pos.y][pos.x] = '0';
		if (game->collectible == 0)
			return (ft_do_end(game, pos, 'D'));
		else
			game->map[pos.y][pos.x + 1] = 'D';
		game->type = 21;
		ft_putnbr_fd(game->moves++, 1);
		ft_putstr_fd("\n", 1);
		return (0);
	}
	return (ft_do_die(game, pos, 'D'));
}
