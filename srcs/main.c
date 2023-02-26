/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:12:01 by galtange          #+#    #+#             */
/*   Updated: 2022/11/01 15:47:58 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	t_game	game;

	if (ac == 1)
		return (ft_error("Error: Please choose the map!\n"));
	else if (ac != 2)
		return (ft_error("Error: this project accept only 2args!\n"));
	if (!ft_extmap(av[1]))
		return (ft_error("Error: Wrong path or not .ber map!\n"));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("Error: map file not found\n"));
	game.map = ft_readmap(fd);
	if (!game.map)
		return (ft_end_error(fd, &game));
	close (fd);
	solong(game);
	ft_free(game.map, ft_splitsize(game.map));
	return (0);
}
