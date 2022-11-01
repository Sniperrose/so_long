/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:07:08 by galtange          #+#    #+#             */
/*   Updated: 2022/10/31 18:12:25 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *all, char const *argv)
{
	char	*str;
	int		i;
	int		j;

	if (!all && !argv)
		return (NULL);
	str = malloc((ft_strlen(all) + ft_strlen(argv) + 1) * sizeof(char));
	if (!str)
	{
		free(all);
		return (NULL);
	}
	i = 0;
	while (all[i] != '\0')
	{
		str[i] = all[i];
		i++;
	}
	j = 0;
	while (argv[j] != '\0')
		str[i++] = argv[j++];
	str[i] = '\0';
	free (all);
	return (str);
}
