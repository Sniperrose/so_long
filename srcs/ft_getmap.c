/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:05:38 by galtange          #+#    #+#             */
/*   Updated: 2022/10/24 18:10:20 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_error(char *str)
{
	ft_putstr_fd(str, 1);
	return (0);
}

size_t	ft_splitsize(char **str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

char	*ft_joinall(int fd)
{
	char	*line;
	char	*all;
	int		i;

	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	all = NULL;
	i = 0;
	while (line != NULL)
	{
		if (i == 0)
			all = ft_strdup(line);
		else
			all = ft_strjoin(all, line);
		if (!all)
		{
			free(line);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (all);
}

char	**ft_readmap(int fd)
{
	char	*all;
	char	**map;

	all = ft_joinall(fd);
	if (!all)
		return (NULL);
	map = (char **)malloc((ft_count(all, '\n') + 1) * sizeof(char *));
	if (!map)
	{
		free(all);
		return (NULL);
	}
	ft_split2(map, all, '\n', ft_count(all, '\n') + 1);
	if (!map)
	{
		free(all);
		return (NULL);
	}
	free(all);
	return (map);
}
