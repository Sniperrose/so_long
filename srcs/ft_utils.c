/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:01:53 by galtange          #+#    #+#             */
/*   Updated: 2022/10/31 18:01:55 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_image	ft_new_sprite(void *ptr, char *path)
{
	t_image	img;

	img.pointer = mlx_xpm_file_to_image(ptr, path, &img.size.x, &img.size.y);
	return (img);
}

int	ft_freeimgs(t_game *game)
{
	mlx_destroy_image (game->ptr, game->imgs.coll.pointer);
	mlx_destroy_image (game->ptr, game->imgs.exit.pointer);
	mlx_destroy_image (game->ptr, game->imgs.player10.pointer);
	mlx_destroy_image (game->ptr, game->imgs.player11.pointer);
	mlx_destroy_image (game->ptr, game->imgs.player20.pointer);
	mlx_destroy_image (game->ptr, game->imgs.player21.pointer);
	mlx_destroy_image (game->ptr, game->imgs.player30.pointer);
	mlx_destroy_image (game->ptr, game->imgs.player31.pointer);
	mlx_destroy_image (game->ptr, game->imgs.player40.pointer);
	mlx_destroy_image (game->ptr, game->imgs.player41.pointer);
	mlx_destroy_image (game->ptr, game->imgs.space.pointer);
	mlx_destroy_image (game->ptr, game->imgs.wall.pointer);
	return (0);
}

int	ft_check_imgpaths(void)
{
	int	fd[13];
	int	i;

	fd[0] = open("imgs/E.xpm", O_RDONLY);
	fd[1] = open("imgs/0.xpm", O_RDONLY);
	fd[2] = open("imgs/1.xpm", O_RDONLY);
	fd[3] = open("imgs/10.xpm", O_RDONLY);
	fd[4] = open("imgs/11.xpm", O_RDONLY);
	fd[5] = open("imgs/20.xpm", O_RDONLY);
	fd[6] = open("imgs/21.xpm", O_RDONLY);
	fd[7] = open("imgs/30.xpm", O_RDONLY);
	fd[8] = open("imgs/31.xpm", O_RDONLY);
	fd[9] = open("imgs/40.xpm", O_RDONLY);
	fd[10] = open("imgs/41.xpm", O_RDONLY);
	fd[11] = open("imgs/C.xpm", O_RDONLY);
	i = -1;
	while (++i < 12)
	{	
		close (fd[i]);
		if (fd[i] < 0)
			return (ft_error("Please check the image paths!\n"));
	}
	return (1);
}

int	ft_end_error(int fd, t_game *g)
{
	if (g->map)
		ft_free(g->map, ft_splitsize(g->map));
	ft_putstr_fd("Error: Cant read the map!\n", 1);
	close (fd);
	return (0);
}

int	ft_extmap(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = (int) ft_strlen(str) - 4;
	if (ft_strncmp(&str[i], ".ber", 4) != 0)
		return (0);
	return (1);
}
