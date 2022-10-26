/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:12:01 by galtange          #+#    #+#             */
/*   Updated: 2022/10/24 18:13:50 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_end_error(int fd)
{
	ft_putstr_fd("Error\n", 1);
	close (fd);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_game	mlx;

	if (ac == 1)
	{
		ft_putstr_fd("please choose the map!\n", 1);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (0);
	mlx.map = ft_readmap(fd);
	if (!mlx.map)
		return (ft_end_error(fd));
	solong(mlx);
	ft_free(mlx.map, ft_splitsize(mlx.map));
	close (fd);
	return (0);
}
