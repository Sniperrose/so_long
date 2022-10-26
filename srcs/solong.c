#include "../include/so_long.h"
#include <X11/keysym.h>

void    *solong(t_game mlx)
{
    mlx.collectible = ft_mapcheck(mlx.map);
    if (!mlx.collectible)
        return (NULL);
    int i = 0;
    while (mlx.map[i])
    {
        printf("%s\n", mlx.map[i]);
        i++;
    }

    t_image img;
    mlx.ptr = mlx_init();
    mlx.win = mlx_new_window(mlx.ptr, 1000, 1000, "so_long");

    test.img = mlx_xpm_file_to_image(mlx.ptr, "imgs/seoho.xpm", test.widht, test.heigth);
    mlx_put_image_to_window(mlx.ptr, mlx.win, test.img, 0, 0);
    mlx_loop(mlx.ptr);
    return (mlx.ptr);
}