# include "../include/so_long.h"

// typedef struct s_mlx
// {
//     void    *mlx;
//     void    *win;
//     // void    *image;

// }              t_mlx;

// typedef struct s_img
// {
//     void    *image;
//     int     *widht;
//     int     *height;

// }              t_img;


void    *ft_image()
{
    t_mlx   new;

    new.mlx = mlx_init();
    new.win = mlx_new_window(new.mlx, 1920, 1080, "Test img!");
    
    t_img   image;
    image.image = mlx_xpm_file_to_image(new.mlx, "srcs/seoho.xpm", image.widht, image.height);
    
    mlx_put_image_to_window(new.mlx, new.win, image.image, 0, 0);

    mlx_loop(new.mlx);
    return (new.mlx);
}