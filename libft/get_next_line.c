/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:15:23 by galtange          #+#    #+#             */
/*   Updated: 2022/10/31 18:15:25 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_read(int fd, char *c)
{
	static char	str_buff[BUFFER_SIZE];
	static int	readed = 0;
	static int	i = 0;

	if (i < readed)
	{
		*c = str_buff[i++];
		return (1);
	}
	readed = read(fd, str_buff, BUFFER_SIZE);
	if (readed <= 0)
		return (readed);
	i = 0;
	*c = str_buff[i++];
	return (1);
}

char	*get_next_line(int fd)
{
	static char	str_save[32000];
	char		*line;
	int			ret_val;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	i = 0;
	while (1)
	{
		ret_val = ft_read(fd, &str_save[i]);
		if (ret_val < 0)
			return (0);
		if (!ret_val || str_save[i] == '\n')
			break ;
		i++;
	}
	if (ret_val > 0)
		str_save[i++] = '\n';
	str_save[i] = '\0';
	if (ft_strlen(str_save) == 0)
		return (0);
	line = ft_strdup(str_save);
	return (&line[0]);
}
