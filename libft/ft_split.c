/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:30:52 by galtange          #+#    #+#             */
/*   Updated: 2022/01/05 19:33:50 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	counting_c(const char *s, char c)
{
	size_t	line;
	int		i;

	line = 0;
	i = 0;
	while (*s != '\0' && *s == c)
		s++;
	while (*s != '\0')
	{
		if (*s != c && i == 0)
		{
			line++;
			i = 1;
		}
		if (i == 1 && *s == c)
			i = 0;
		s++;
	}
	return (line);
}

size_t	ft_end(const char *s, char c)
{
	size_t	end;

	end = 0;
	while (*s != c && *s != '\0')
	{
		end++;
		s++;
	}
	return (end);
}

void	ft_free(char **ptr, size_t line)
{
	while (0 < line)
	{
		free(ptr[line]);
		line--;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	line;

	if (!s)
		return (NULL);
	result = (char **)malloc((counting_c(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	line = 0;
	while (line < counting_c(s, c) && s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		result[line] = ft_substr(s, i, ft_end(&s[i], c));
		if (!result[line])
		{
			ft_free(result, line);
			return (NULL);
		}
		i = i + ft_end(&s[i], c);
		line++;
	}
	result[line] = NULL;
	return (result);
}
