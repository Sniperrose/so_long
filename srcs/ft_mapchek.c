/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapchek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:55:06 by galtange          #+#    #+#             */
/*   Updated: 2022/11/01 15:58:58 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_bzero(int *nbr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		nbr[i] = 0;
		i++;
	}
	return ;
}

int	ft_wallcheck(char **map, int i, size_t x)
{
	int	j;

	j = 0;
	while (map[0][j] && map[i][j])
	{
		if (map[0][j] != '1' || map[i][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (j < i)
	{
		if (map[j][0] != '1' || map[j][x] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	ft_comptcheck(char **map, int i, int j)
{
	int	comp[3];

	ft_bzero(comp, 3);
	while (map[i] != NULL)
	{
		j = 1;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				comp[0] += 1;
			else if (map[i][j] == 'E')
				comp[1] += 1;
			else if (map[i][j] == 'P')
				comp[2] += 1;
			else if (map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	if (comp[0] == 0 || comp[1] != 1 || comp[2] != 1)
		return (0);
	return (comp[0]);
}

int	ft_mapcheck(char **map)
{
	size_t	x;
	int		cntr;
	int		y;

	y = 0;
	x = ft_strlen(map[y++]);
	while (map[y] != NULL)
	{
		if (ft_strlen(map[y]) != x)
			return (ft_error("Error: Not rectangular map!\n"));
		y++;
	}
	if (!ft_wallcheck(map, y - 1, x - 1))
		return (ft_error("Error: Map must be closed by walls!\n"));
	cntr = ft_comptcheck(map, 0, 0);
	if (!ft_validp(map, ft_splitsize(map)))
		return (ft_error("Error: Valid path not found!\n"));
	if (cntr == 0)
		return (ft_error("Error: Not valid map!\n"));
	return (cntr);
}
