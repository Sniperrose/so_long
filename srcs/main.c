# include "../include/so_long.h"
# include "../minilibx-linux/mlx.h"

int ft_end_error(int fd)
{
    ft_putstr_fd("Error\n", 1);
    close (fd);
    return (0);
}

int main(int ac, char **av)
{
    int fd;
    char    **map;

    if (ac == 1)
    {
        ft_putstr_fd("please choose the map!\n", 1);
        return (0);
    }
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return (0);
    map = ft_readmap(fd);
    if (!map)
        return (ft_end_error(fd));
    int i = 0;
    while (map[i] != NULL)
        printf("%s\n", map[i++]);
    // if (!ft_solong(map))
    // {
    //     ft_free(map, ft_splitsize(map));
    //     return (ft_end_error(fd));
    // }

    if (!ft_sosoolong(map))
    {
        ft_free(map, ft_splitsize(map));
        return (ft_end_error(fd));
    }
    // ft_test();
    // ft_image();
    ft_free(map, i);
    close (fd);
    return (0);
}
