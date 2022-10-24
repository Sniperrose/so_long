// # include "../include/so_long.h"


// // void    *ft_displayimg(t_mlx m, char *patch)
// // {
// //     // t_mlx   new;

// //     // new.mlx = mlx_init();
// //     // new.win = mlx_new_window(new.mlx, 1920, 1080, "Test img!");
    
// //     t_img   image;
// //     image.image = mlx_xpm_file_to_image(m.mlx, patch, image.widht, image.height);
    
// //     mlx_put_image_to_window(m.mlx, m.win, image.image, m.x, m.y);

// //     // mlx_loop(new.mlx);
// //     return (m.mlx);
// // }


// void    *ft_drawscrean(t_mlx screan, char **map)
// {
//     int i = 0;
//     int j;

//     screan.x = 0;
//     screan.y = 0;
//     t_img   img;
//     while(map[i])
//     {
//         j = 0;
//         while(map[i][j])
//         {
//             if (map[i][j] == '1')
//                 img.image = mlx_xpm_file_to_image(screan.mlx, "srcs/wall.xpm", img.widht, img.height);
//             else if (map[i][j] == '0')
//                 img.image = mlx_xpm_file_to_image(screan.mlx, "srcs/space.xpm", img.widht, img.height);
//             else if (map[i][j] == 'E')
//                 img.image = mlx_xpm_file_to_image(screan.mlx, "srcs/exit.xpm", img.widht, img.height);
//             else if (map[i][j] == 'C')
//                 img.image = mlx_xpm_file_to_image(screan.mlx, "srcs/col.xpm", img.widht, img.height);
//             else if (map[i][j] == 'P')
//             {
//                 img.image = mlx_xpm_file_to_image(screan.mlx, "srcs/player.xpm", img.widht, img.height);
//                 screan.p_x = i;
//                 screan.p_y = j;
//             }
//             mlx_put_image_to_window(screan.mlx, screan.win, img.image, screan.x, screan.y);
//             screan.x += 64;
//             j++;
//         }
//         screan.x = 0;
//         screan.y += 64;
//         i++;
//     }
//     printf("pos player %dx%d\n", screan.p_x, screan.p_y);
//     return (screan.mlx);
// }

// // int	key_hook(int keycode, t_vars *vars)
// // {
// // 	printf("Hello from key_hook!\n");
// // 	return (0);
// // }


// int ft_move_hook(int keycode, char **map, t_mlx *screan)
// {
//     if (keycode == 100)
//     {
//         map[screan->p_x][screan->p_y] = '0';
//         screan->p_x += 1; 
//         map[screan->p_x][screan->p_y] = 'P';
//     }
//     else
//         return (0);
//     return (1);
// }

// void    ft_do_d(char **map, int x, int y)
// {
//     if (map[x + 1][y] == '1')
//         return ;
//     else
//     {
//         map[x + 1][y] = 'P';
//         map[x][y] = '0';
//     }
// }

// int	handle_input(int keysym, t_mlx *data, char **map)
// {

//     if (keysym == XK_d || keysym == XK_d)
//     {
//         ft_do_d(map, data->p_x, data->p_y);
//     }

//     printf("Keypress: %d\n", keysym);
// 	return (0);
// }

// void    *ft_sosoolong(char **map)
// {
//     t_mlx   screan;

//     if (!ft_validmap(map) || !map)
//         return (NULL);
//     screan.mlx = mlx_init();

//     int x = ((int)ft_strlen(map[0])) * 64;
//     int y = ((int)ft_splitsize(map)) * 64;
//     screan.win = mlx_new_window(screan.mlx, x, y, "so_long!");

//     ft_drawscrean(screan, map);
//     mlx_key_hook(screan.win, &handle_input, &screan);
//     ft_drawscrean(screan, map);
//     mlx_loop(screan.mlx);
//     return (screan.mlx);
// }