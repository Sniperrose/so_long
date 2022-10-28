/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getimages.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:53:31 by galtange          #+#    #+#             */
/*   Updated: 2022/10/27 16:04:56 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_image	ft_new_image(void *ptr, int width, int height)
{
	t_image	img;

	img.pointer = mlx_new_image(ptr, width, height);
	img.size.x = width;
	img.size.y = height;
	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_pp,
			&img.line_size, &img.endian);
	return (img);
}

t_image	ft_new_sprite(void *ptr, char *path)
{
	t_image	img;

	img.pointer = mlx_xpm_file_to_image(ptr, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_pp,
			&img.line_size, &img.endian);
	return (img);
}

t_icon	ft_readimgs(void *ptr, int i)
{
	t_icon	show;

	show.coll = ft_new_sprite(ptr, "imgs/C.xpm");
	show.exit = ft_new_sprite(ptr, "imgs/E.xpm");
	show.space = ft_new_sprite(ptr, "imgs/0.xpm");
	show.wall = ft_new_sprite(ptr, "imgs/1.xpm");
	if (i == 0)
		show.player = ft_new_sprite(ptr, "imgs/P.xpm");
	else if (i == 1)
		show.player = ft_new_sprite(ptr, "imgs/P_L.xpm");
	else if (i == 2)
		show.player = ft_new_sprite(ptr, "imgs/1.xpm");
	return (show);
}

void	*put_img(t_icon show, char c)
{
	if (c == '1')
		return (show.wall.pointer);
	else if (c == 'C')
		return (show.coll.pointer);
	else if (c == 'P')
		return (show.player.pointer);
	else if (c == 'D')
		return (show.player.pointer);
	else if (c == 'E')
		return (show.exit.pointer);
	else if (c == '0')
		return (show.space.pointer);
	return (NULL);
}

void	*display_game(t_game *game, int type)
{
	t_icon		show;
	t_vector	m;
	t_vector	d;
	char		c;

	show = ft_readimgs(game->ptr, type);
	m.x = 0;
	d.x = 0;
	d.y = 0;
	while (game->map[m.x] != NULL)
	{
		m.y = 0;
		while (game->map[m.x][m.y] != '\0')
		{
			c = game->map[m.x][m.y];
			mlx_put_image_to_window(game->ptr, game->win,
				put_img(show, c), d.x, d.y);
			d.x += res;
			m.y++;
		}
		d.x = 0;
		d.y += res;
		m.x++;
	}
	return (game->ptr);
}
