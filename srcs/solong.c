#include "../include/so_long.h"
#include <X11/keysym.h>

// void    *ft_drawgame(t_game game, char **map)
// {
//     int i = 0;
//     int j;

//     game.x = 0;
//     game.y = 0;
//     t_image   img;
//     while(map[i])
//     {
//         j = 0;
//         while(map[i][j])
//         {
//             if (map[i][j] == '1')
//             {
//                 img.pointer = mlx_xpm_file_to_image(game.ptr, "srcs/wall.xpm", img., img.heigth);
//                 mlx_put_image_to_window(game.ptr, game.win, img.pointer, game.x, game.y);
//             }
//             // else if (map[i][j] == '0')
//             //     img.pointer = mlx_xpm_file_to_image(game.ptr, "imgs/grass64.xpm", img.widht, img.heigth);
//             // else if (map[i][j] == 'E')
//             //     img.pointer = mlx_xpm_file_to_image(game.ptr, "srcs/exit.xpm", img.widht, img.heigth);
//             // else if (map[i][j] == 'C')
//             //     img.pointer = mlx_xpm_file_to_image(game.ptr, "srcs/col.xpm", img.widht, img.heigth);
//             // else if (map[i][j] == 'P')
//             //     img.pointer = mlx_xpm_file_to_image(game.ptr, "imgs/bunny64.xpm", img.widht, img.heigth);
//             mlx_put_image_to_window(game.ptr, game.win, img.pointer, game.x, game.y);
//             game.x += 64;
//             j++;
//         }
//         game.x = 0;
//         game.y += 64;
//         i++;
//     }
//     return (game.ptr);
// }

t_image ft_new_sprite(void *ptr, char *path)
{
    t_image img;

    img.pointer = mlx_xpm_file_to_image(ptr, path, &img.size.x, &img.size.y);
    // img.pixels = mlx_get_data_addr(img.refe)

    return (img);
}

void    *test(void *ptr, void *win)
{
    t_image new;

    new = ft_new_sprite(ptr, "imgs/bunny64.xpm");
    mlx_put_image_to_window(ptr, win, new.pointer, 0, 0);

    return (ptr);
}
void    *test_bg(t_game game)
{
    t_vector m;
    t_vector size;
    t_image wall;

    m.x = 0;
    size.x = 0;
    size.y = 0;
    while(game.map[m.x] != 0)
    {
        m.y = 0;
        while (game.map[m.x][m.y] != '\0')
        {
            if (game.map[m.x][m.y] == '1')
                wall = ft_new_sprite(game.ptr, "imgs/1.xpm");
            else
                wall = ft_new_sprite(game.ptr, "imgs/0.xpm");
            mlx_put_image_to_window(game.ptr, game.win, wall.pointer, size.x, size.y);
            m.y++;
            size.x += 64;
        }
        size.x = 0;
        size.y += 64;
        m.x++;
    }
    return (game.ptr);
}

void    *solong(t_game game)
{
    game.collectible = ft_mapcheck(game.map);
    if (!game.collectible)
        return (NULL);
    int i = 0;
    while (game.map[i])
    {
        printf("%s\n", game.map[i]);
        i++;
    }

    game.x = ((int)ft_strlen(game.map[0])) * 64;
    game.y = ((int)ft_splitsize(game.map)) * 64;
    game.ptr = mlx_init();
    game.win = mlx_new_window(game.ptr, game.x, game.y, "so_long_test");


    test(game.ptr, game.win);
    test_bg(game);
    //   test(game.ptr, game.win);
    mlx_loop(game.ptr);
    return (game.ptr);
}