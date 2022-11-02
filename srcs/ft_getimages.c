/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getimages.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:53:31 by galtange          #+#    #+#             */
/*   Updated: 2022/11/01 15:47:15 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_icon	ft_readimgs(void *ptr)
{
	t_icon	show;

	show.coll = ft_new_sprite(ptr, "imgs/C.xpm");
	show.exit = ft_new_sprite(ptr, "imgs/E.xpm");
	show.space = ft_new_sprite(ptr, "imgs/0.xpm");
	show.wall = ft_new_sprite(ptr, "imgs/1.xpm");
	show.player10 = ft_new_sprite(ptr, "imgs/10.xpm");
	show.player11 = ft_new_sprite(ptr, "imgs/11.xpm");
	show.player20 = ft_new_sprite(ptr, "imgs/20.xpm");
	show.player21 = ft_new_sprite(ptr, "imgs/21.xpm");
	show.player30 = ft_new_sprite(ptr, "imgs/30.xpm");
	show.player31 = ft_new_sprite(ptr, "imgs/31.xpm");
	show.player40 = ft_new_sprite(ptr, "imgs/40.xpm");
	show.player41 = ft_new_sprite(ptr, "imgs/41.xpm");
	return (show);
}

int	ft_getimgs(t_game *game)
{
	game->imgs = ft_readimgs(game->ptr);
	if (!game->imgs.coll.pointer || !game->imgs.exit.pointer)
		return (ft_freeimgs(game));
	else if (!game->imgs.space.pointer || !game->imgs.wall.pointer)
		return (0);
	else if (!game->imgs.player10.pointer || !game->imgs.player11.pointer)
		return (0);
	else if (!game->imgs.player20.pointer || !game->imgs.player21.pointer)
		return (0);
	else if (!game->imgs.player30.pointer || !game->imgs.player31.pointer)
		return (0);
	else if (!game->imgs.player40.pointer || !game->imgs.player41.pointer)
		return (0);
	return (1);
}

void	*put_img(t_icon show, char c)
{
	if (c == '1')
		return (show.wall.pointer);
	else if (c == 'C')
		return (show.coll.pointer);
	else if (c == 'E')
		return (show.exit.pointer);
	else if (c == '0')
		return (show.space.pointer);
	return (NULL);
}

void	*put_player(t_icon show, int i)
{
	if (i == 10)
		return (show.player10.pointer);
	else if (i == 11)
		return (show.player11.pointer);
	else if (i == 20)
		return (show.player20.pointer);
	else if (i == 21)
		return (show.player21.pointer);
	else if (i == 30 || i == 0)
		return (show.player30.pointer);
	else if (i == 31)
		return (show.player31.pointer);
	else if (i == 40)
		return (show.player40.pointer);
	else
		return (show.player41.pointer);
	return (NULL);
}

void	*display_game(t_game *game, int type)
{
	t_vector	m;
	t_vector	d;

	m.x = 0;
	d.x = 0;
	d.y = 0;
	while (game->map[m.x] != NULL)
	{
		m.y = 0;
		while (game->map[m.x][m.y] != '\0')
		{
			if (game->map[m.x][m.y] == 'P' || game->map[m.x][m.y] == 'D')
				mlx_put_image_to_window(game->ptr, game->win,
					put_player(game->imgs, type), d.x, d.y);
			else
				mlx_put_image_to_window(game->ptr, game->win,
					put_img(game->imgs, game->map[m.x][m.y]), d.x, d.y);
			d.x += RES;
			m.y++;
		}
		d.x = 0;
		d.y += RES;
		m.x++;
	}
	return (game->ptr);
}
