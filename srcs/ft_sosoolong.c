# include "../include/so_long.h"


// void    *ft_displayimg(t_mlx m, char *patch)
// {
//     // t_mlx   new;

//     // new.mlx = mlx_init();
//     // new.win = mlx_new_window(new.mlx, 1920, 1080, "Test img!");
    
//     t_img   image;
//     image.image = mlx_xpm_file_to_image(m.mlx, patch, image.widht, image.height);
    
//     mlx_put_image_to_window(m.mlx, m.win, image.image, m.x, m.y);

//     // mlx_loop(new.mlx);
//     return (m.mlx);
// }


void    *ft_drawscrean(t_mlx screan, char **map)
{
    int i = 0;
    int j;

    t_img   img;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] == '1')
                img.image = mlx_xpm_file_to_image(screan.mlx, "srcs/wall.xpm", img.widht, img.height);
            else if (map[i][j] == '0')
                img.image = mlx_xpm_file_to_image(screan.mlx, "srcs/space.xpm", img.widht, img.height);
            else if (map[i][j] == 'E')
                img.image = mlx_xpm_file_to_image(screan.mlx, "srcs/exit.xpm", img.widht, img.height);
            else if (map[i][j] == 'C')
                img.image = mlx_xpm_file_to_image(screan.mlx, "srcs/col.xpm", img.widht, img.height);
            else if (map[i][j] == 'P')
                img.image = mlx_xpm_file_to_image(screan.mlx, "srcs/player.xpm", img.widht, img.height);
            mlx_put_image_to_window(screan.mlx, screan.win, img.image, screan.x, screan.y);
            screan.x += 64;
            j++;
        }
        screan.x = 0;
        screan.y += 64;
        i++;
    }
    return (screan.mlx);
}

void    *ft_sosoolong(char **map)
{
    t_mlx   screan;

    if (!ft_validmap(map) || !map)
        return (NULL);
    screan.mlx = mlx_init();

    int x = ((int)ft_strlen(map[0])) * 64;
    int y = ((int)ft_splitsize(map)) * 64;
    screan.win = mlx_new_window(screan.mlx, x, y, "so_long!");

    screan.x = 0;
    screan.y = 0;

    ft_drawscrean(screan, map);

    mlx_loop(screan.mlx);
    return (screan.mlx);
}