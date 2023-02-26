/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:40:45 by galtange          #+#    #+#             */
/*   Updated: 2022/10/30 21:56:42 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_up_d(t_game *game, int x, int y)
{
	game->map[y][x] = 'E';
	if (game->map[y - 1][x] == 'C')
	{
		game->collectible -= 1;
		game->map[y - 1][x] = 'P';
		game->type = 10;
	}
	else if (game->map[y - 1][x] == '0')
	{
		game->map[y - 1][x] = 'P';
		game->map[y][x] = 'E';
		game->type = 10;
	}
	ft_putnbr_fd(game->moves++, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

int	can_i_move_up(t_game *game, t_vector pos)
{
	if (game->map[pos.y - 1][pos.x] == '1')
		return (0);
	if (game->map[pos.y][pos.x] == 'D')
		return (ft_up_d(game, pos.x, pos.y));
	game->type = 10;
	if (game->map[pos.y - 1][pos.x] == '0')
		return (ft_do_move(game, pos, 'W'));
	else if (game->map[pos.y - 1][pos.x] == 'C')
	{
		game->collectible -= 1;
		return (ft_do_move(game, pos, 'W'));
	}
	else if (game->map[pos.y - 1][pos.x] == 'E')
	{
		game->map[pos.y][pos.x] = '0';
		if (game->collectible == 0)
			return (ft_do_end(game, pos, 'W'));
		else
			game->map[pos.y - 1][pos.x] = 'D';
		game->type = 11;
		ft_putnbr_fd(game->moves++, 1);
		ft_putstr_fd("\n", 1);
		return (0);
	}
	return (ft_do_die(game, pos, 'W'));
}

int	ft_down_d(t_game *game, int x, int y)
{
	game->map[y][x] = 'E';
	if (game->map[y + 1][x] == 'C')
	{
		game->collectible -= 1;
		game->map[y + 1][x] = 'P';
		game->type = 30;
	}
	else if (game->map[y + 1][x] == '0')
	{
		game->map[y + 1][x] = 'P';
		game->map[y][x] = 'E';
		game->type = 30;
	}
	ft_putnbr_fd(game->moves++, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

int	can_i_move_down(t_game *game, t_vector pos)
{
	if (game->map[pos.y + 1][pos.x] == '1')
		return (0);
	if (game->map[pos.y][pos.x] == 'D')
		return (ft_down_d(game, pos.x, pos.y));
	game->type = 30;
	if (game->map[pos.y + 1][pos.x] == '0')
		return (ft_do_move(game, pos, 'S'));
	else if (game->map[pos.y + 1][pos.x] == 'C')
	{
		game->collectible -= 1;
		return (ft_do_move(game, pos, 'S'));
	}
	else if (game->map[pos.y + 1][pos.x] == 'E')
	{
		game->map[pos.y][pos.x] = '0';
		if (game->collectible == 0)
			return (ft_do_end(game, pos, 'S'));
		else
			game->map[pos.y + 1][pos.x] = 'D';
		game->type = 31;
		ft_putnbr_fd(game->moves++, 1);
		ft_putstr_fd("\n", 1);
		return (0);
	}
	return (ft_do_die(game, pos, 'S'));
}
