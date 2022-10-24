# include "../include/so_long.h"

char    *ft_path(char c)
{
    if (c == '1')
        return ("imgs/fence64.xpm");
    else if (c == 'P')
        return ("imgs/bunny64.xpm");
    else if (c == 'C')
        return ("imgs/carrot.xpm");
    else if (c == 'E')
        return ("imgs/sink.xpm");
    else
        return("imgs/grass64.xpm");
}

void    *ft_drawscrean(t_mlx screan, char **map)
{
    int i = 0;
    int j;

    screan.x = 0;
    screan.y = 0;

    t_img   img;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            img.image = mlx_xpm_file_to_image(screan.mlx, ft_path(map[i][j]), img.w, img.h);
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

void    *solong(t_mlx mlx)
{
    mlx.cntr = ft_mapcheck(mlx.map);
    if (!mlx.cntr)
        return (NULL);

    mlx.x = ((int)ft_strlen(mlx.map[0])) * 64;
    mlx.y = ((int)ft_splitsize(mlx.map)) * 64;
    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, mlx.x, mlx.y, "so_long!");
    ft_drawscrean(mlx, mlx.map);

    mlx_loop(mlx.mlx);
    return (mlx.mlx);
}
