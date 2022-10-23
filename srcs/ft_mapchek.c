# include "../include/so_long.h"

int ft_wallcheck(char **map, int i, size_t x)
{
    int  j;

    j = 0;
    while(map[0][j] && map[i][j])
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

int ft_comptcheck(char  **map)
{
    int comp[3];
    int i;
    int j;

    comp[0] = 0;
    comp[1] = 0;
    comp[2] = 0;
    i = 1;
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
    if (comp[0] == 0 || comp[1] == 0 || comp[2] != 1)
        return (0);
    return (1);
}

int ft_validmap(char **map)
{
    size_t x;
    int i;

    i = 0;
    x = ft_strlen(map[i++]);
    while (map[i] != NULL)
    {
        if (x != ft_strlen(map[i]))
            return (ft_error("Error: Not rectangular map!\n"));
        i++;
    }
    if (!ft_wallcheck(map, i - 1, x - 1))
        return (ft_error("Error: Map must be closed by walls!\n"));
    if (!ft_comptcheck(map))
        return (ft_error("Error: map error!\n"));
    return (i);
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