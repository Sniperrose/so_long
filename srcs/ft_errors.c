/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:38:57 by galtange          #+#    #+#             */
/*   Updated: 2022/11/04 14:39:56 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_err(t_game *game, char *str)
{
	if (game->ptr)
		free(game->ptr);
	ft_putstr_fd(str, 1);
	return (0);
}

int	ft_end_error(int fd, t_game *g)
{
	if (g->map)
		ft_free(g->map, ft_splitsize(g->map));
	ft_putstr_fd("Error: Cant read the map!\n", 1);
	close (fd);
	return (0);
}

int	ft_win_err(t_game *game)
{
	ft_freeimgs(game);
	ft_freeimgs2(game);
	ft_freenbrs(game);
	mlx_destroy_display (game->ptr);
	free(game->ptr);
	ft_putstr_fd("Error: Cant initialize window\n", 1);
	return (0);
}

int	ft_image_err(t_game *game)
{
	ft_freeimgs(game);
	ft_freeimgs2(game);
	ft_freenbrs(game);
	mlx_destroy_display (game->ptr);
	free(game->ptr);
	ft_putstr_fd("Error: Cant open the images\n", 1);
	return (0);
}
