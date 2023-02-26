/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeimgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:04:24 by galtange          #+#    #+#             */
/*   Updated: 2023/02/18 22:04:25 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_freeimgs(t_game *game)
{
	if (game->imgs.coll.pointer)
		mlx_destroy_image (game->ptr, game->imgs.coll.pointer);
	if (game->imgs.exit.pointer)
		mlx_destroy_image (game->ptr, game->imgs.exit.pointer);
	if (game->imgs.player10.pointer)
		mlx_destroy_image (game->ptr, game->imgs.player10.pointer);
	if (game->imgs.player11.pointer)
		mlx_destroy_image (game->ptr, game->imgs.player11.pointer);
	if (game->imgs.player20.pointer)
		mlx_destroy_image (game->ptr, game->imgs.player20.pointer);
	if (game->imgs.player21.pointer)
		mlx_destroy_image (game->ptr, game->imgs.player21.pointer);
	if (game->imgs.player30.pointer)
		mlx_destroy_image (game->ptr, game->imgs.player30.pointer);
	if (game->imgs.player31.pointer)
		mlx_destroy_image (game->ptr, game->imgs.player31.pointer);
	if (game->imgs.player40.pointer)
		mlx_destroy_image (game->ptr, game->imgs.player40.pointer);
	if (game->imgs.player41.pointer)
		mlx_destroy_image (game->ptr, game->imgs.player41.pointer);
	if (game->imgs.space.pointer)
		mlx_destroy_image (game->ptr, game->imgs.space.pointer);
	if (game->imgs.wall.pointer)
		mlx_destroy_image (game->ptr, game->imgs.wall.pointer);
	return (0);
}

int	ft_freeimgs2(t_game *game)
{
	if (game->imgs.trap1.pointer)
		mlx_destroy_image (game->ptr, game->imgs.trap1.pointer);
	if (game->imgs.trap2.pointer)
		mlx_destroy_image (game->ptr, game->imgs.trap2.pointer);
	if (game->imgs.died.pointer)
		mlx_destroy_image (game->ptr, game->imgs.died.pointer);
	if (game->imgs.won.pointer)
		mlx_destroy_image (game->ptr, game->imgs.won.pointer);
	return (0);
}

int	ft_freenbrs(t_game *game)
{
	if (game->nbr.n0.pointer)
		mlx_destroy_image (game->ptr, game->nbr.n0.pointer);
	if (game->nbr.n1.pointer)
		mlx_destroy_image (game->ptr, game->nbr.n1.pointer);
	if (game->nbr.n2.pointer)
		mlx_destroy_image (game->ptr, game->nbr.n2.pointer);
	if (game->nbr.n3.pointer)
		mlx_destroy_image (game->ptr, game->nbr.n3.pointer);
	if (game->nbr.n4.pointer)
		mlx_destroy_image (game->ptr, game->nbr.n4.pointer);
	if (game->nbr.n5.pointer)
		mlx_destroy_image (game->ptr, game->nbr.n5.pointer);
	if (game->nbr.n6.pointer)
		mlx_destroy_image (game->ptr, game->nbr.n6.pointer);
	if (game->nbr.n7.pointer)
		mlx_destroy_image (game->ptr, game->nbr.n7.pointer);
	if (game->nbr.n8.pointer)
		mlx_destroy_image (game->ptr, game->nbr.n8.pointer);
	if (game->nbr.n9.pointer)
		mlx_destroy_image (game->ptr, game->nbr.n9.pointer);
	return (0);
}
