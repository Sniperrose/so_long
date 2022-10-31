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

int	ft_end_error(int fd, t_game *g)
{
	if (g->map)
		ft_free(g->map, ft_splitsize(g->map));
	ft_putstr_fd("Error\n", 1);
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

int	main(int ac, char **av)
{
	int		fd;
	t_game	mlx;

	if (ac == 1)
	{
		ft_putstr_fd("please choose the map!\n", 1);
		return (0);
	}
	if (!ft_extmap(av[1]))
		return (ft_error("Sorry, i can accept only *.ber maps!\n"));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (0);
	mlx.map = ft_readmap(fd);
	if (!mlx.map)
		return (ft_end_error(fd, &mlx));
	if (!solong(mlx))
		return (ft_end_error(fd, &mlx));
	ft_free(mlx.map, ft_splitsize(mlx.map));
	close (fd);
	return (0);
}
