/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validpath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:49:15 by galtange          #+#    #+#             */
/*   Updated: 2022/11/01 15:59:37 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_copymap(char **tmp, char **map)
{
	int	i;

	if (!tmp || !map)
		return (0);
	i = 0;
	while (map[i])
	{
		tmp[i] = ft_strdup(map[i]);
		if (!tmp[i])
		{
			ft_free(tmp, i);
			return (0);
		}
		i++;
	}
	tmp[i] = NULL;
	return (1);
}

int	ft_checkval(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_injection(char **map, int i, int j)
{
	int	inj;

	inj = 0;
	if (map[i][j - 1] != '1' && map[i][j - 1] != 'P')
	{
		map[i][j - 1] = 'P';
		inj++;
	}
	if (map[i][j + 1] != '1' && map[i][j + 1] != 'P')
	{
		map[i][j + 1] = 'P';
		inj++;
	}
	if (map[i - 1][j] != '1' && map[i - 1][j] != 'P')
	{
		map[i - 1][j] = 'P';
		inj++;
	}
	if (map[i + 1][j] != '1' && map[i + 1][j] != 'P')
	{
		map[i + 1][j] = 'P';
		inj++;
	}
	return (inj);
}

int	ft_findpath(char **tmp)
{
	int		i;
	size_t	x;
	size_t	y;
	size_t	size;

	size = ft_splitsize(tmp);
	i = -1;
	while (i)
	{
		i = 0;
		x = 0;
		y = 0;
		while (y < size)
		{
			if (tmp[y][x] == 'P')
				i += ft_injection(tmp, y, x);
			x++;
			if (tmp[y][x] == '\0')
			{
				x = 0;
				y++;
			}
		}
	}
	return (ft_checkval(tmp));
}

int	ft_validp(char **map, int size)
{
	char	**tmp;
	int		i;

	if (size < 0)
		return (0);
	tmp = (char **)malloc((size + 1) * sizeof(char *));
	if (!map || !*map || !tmp)
		return (0);
	if (!ft_copymap(tmp, map))
		return (0);
	i = ft_findpath(tmp);
	ft_free(tmp, ft_splitsize(tmp));
	return (i);
}
