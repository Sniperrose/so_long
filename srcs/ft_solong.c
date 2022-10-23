# include "../include/so_long.h"


int handle_no_event(void *mlx, void *win)
{
    (void) mlx;
    (void) win;
    return (0);
}

int handle_keypress(int keysym, void *mlx, void *win)
{
    if (keysym == XK_Escape)
        mlx_destroy_window(mlx, win);

    printf("Keypress: %d\n", keysym);
    return (0);

}

int handle_keyrelease(int keysym, void *data)
{
    (void) data;
    printf("Keyrelease: %d\n", keysym);
    return(0);
}

int handle_button(void *mlx, void *win)
{
    mlx_destroy_window(mlx, win);
    return (0);
}

int    ft_putmap(void *mlx, void *win, int color, int *pos)
{
    void    *image = mlx_new_image(mlx, 64, 64);
    int     pixel_bits;
    int     line_bytes;
    int     endian;
    char    *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);

    if (pixel_bits != 32)
        color = mlx_get_color_value(mlx, color);

    for (int y = 0; y < 64; ++y)
    for (int x = 0; x < 64; ++x)
    {
        int pixel = (y * line_bytes) + (x * 4);

        if (endian == 1)
        {
            buffer[pixel + 0] = (color >> 24);
            buffer[pixel + 1] = (color >> 16) & 0xFF;
            buffer[pixel + 2] = (color >> 8) & 0xFF;
            buffer[pixel + 3] = (color) & 0xFF;
        }
        else if (endian == 0)
        {
            buffer[pixel + 0] = (color) & 0xFF;
            buffer[pixel + 1] = (color >> 8) & 0xFF;
            buffer[pixel + 2] = (color >> 16) & 0xFF;
            buffer[pixel + 3] = (color >> 24);
        }
    }

    mlx_put_image_to_window(mlx, win, image, pos[0], pos[1]);
    return (1);
}

int    ft_putmap2(void *mlx, void *win, char *path, int *pos)
{
    void    *image;
    char    *buffer;
    int height;
    int wigth;
    int     pixel_bits;
    int     line_bytes;
    int     endian;

    image = mlx_xpm_file_to_image(mlx, path, &wigth, &height);
    buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
    mlx_put_image_to_window(mlx, win, image, pos[0], pos[1]);
    return (1);
}

void	*put_image(void *mlx, void *win, int x, int y)
{
    t_img   wall;

    wall.image = mlx_xpm_file_to_image(mlx, "srcs/wall.xpm", wall.widht, wall.height);

    mlx_put_image_to_window(mlx, win, wall.image, x, y);

    return (wall.image);
}

int    ft_putcolor(void *mlx, void *win, char c, int *pos)
{
    int i;

    i = 0;
    if (c == '1')
        i = ft_putmap(mlx, win, 0xFFFF00, pos);
    // if (c == '1')
    //     put_image(mlx, win, pos);
    else if (c == 'P')
        i = ft_putmap(mlx, win, 0x000000, pos);
    else if (c == 'C')
        i = ft_putmap(mlx, win, 0x0000FF, pos);
    else if (c == 'E')
        i = ft_putmap(mlx, win, 0x00FF00, pos);
    else 
        i = ft_putmap(mlx, win, 0xFFFFFF, pos);
    if (!i)
        return (0);
    pos[0] += 64;
    return (1);
}

int ft_drawmap(char **map, int size)
{
    int x;
    int y;

    x = size * ft_strlen(map[0]);
    y = size * ft_splitsize(map);
    
    void    *mlx = mlx_init();
    void    *mlx_win = mlx_new_window(mlx, x, y, "so_long");
    if (!mlx_win)
        return (0);
    int i = 0;
    int j;
    int pos[2];
    pos[0] = 0;
    pos[1] = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (!ft_putcolor(mlx, mlx_win, map[i][j], pos))
                return (0);
            j++;
        }
        pos[0] = 0;
        pos[1] += size;
        i++;
    }
    mlx_loop(mlx);

    mlx_loop_hook(mlx_win, &handle_no_event, mlx);
    mlx_hook(mlx_win, KeyPress, KeyPressMask, &handle_keypress, mlx);  
    mlx_hook(mlx_win, DestroyNotify, StructureNotifyMask, &handle_button, mlx);
    return (1);
}

int ft_solong(char **map)
{
    if (!ft_validmap(map) || !map)
        return (0);
    if (!ft_drawmap(map, 64))
        return (0);
    return (1);
}