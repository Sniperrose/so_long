#include "../include/so_long.h"

// void    *handle_move(int key, t_game *game)
// {
//     if (key == XK_d || key == XK_D)
//         printf ("D\n");
//     return 
// }

int handle_exit(int keysym, t_game *game)
{
    if (keysym == XK_Escape)
        mlx_destroy_window(game->ptr, game->win);
    return (0);
}


void    ft_printmap(char **map)
{
    int i = 0;

    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;  
    }
    return ;
}

void    ft_do_move(t_game *game, t_vector pos, char dir)
{
    game->map[pos.y][pos.x] = '0';
    if (dir == 'D')
    {
        game->map[pos.y][pos.x + 1] = 'P';
        printf("right\n");
    }
    else if (dir == 'A')
    {
        game->map[pos.y][pos.x - 1] = 'P';
        printf("left\n");
    }
    else if (dir == 'W')
    {
        game->map[pos.y - 1][pos.x] = 'P';
        printf("up\n");
    }
    else if (dir == 'S')
    {
        game->map[pos.y + 1][pos.x] = 'P';
        printf("down\n");
    }
    else
        return ;
}



int	handle_keypress(int keysym, t_game *game)
{
    t_vector pos;

    pos = get_pos_player(game->map);
    if (keysym == XK_d || keysym == XK_D)
    {
        if (can_i_move_right(game, pos.x, pos.y))
            ft_do_move(game, pos, 'D');
        else if (can_i_move_right(game, pos.x, pos.y) == 2)
            game->map[pos.x][pos.y] = '0';
    }
    else    if (keysym == XK_W || keysym == XK_w)
    {
        if (can_i_move_up(game, pos.x, pos.y))
            ft_do_move(game, pos, 'W');
        else if (can_i_move_up(game, pos.x, pos.y) == 2)
            game->map[pos.x][pos.y] = '0';
    }
    else    if (keysym == XK_A || keysym == XK_a)
    {
        if (can_i_move_left(game, pos.x, pos.y))
            ft_do_move(game, pos, 'A');
        if (can_i_move_left(game, pos.x, pos.y) == 2)
            game->map[pos.x][pos.y] = 'C';
    }
    else    if (keysym == XK_S || keysym == XK_s)
    {
        if (can_i_move_down(game, pos.x, pos.y))
            ft_do_move(game, pos, 'S');
        if (can_i_move_down(game, pos.x, pos.y) == 2)
            game->map[pos.x][pos.y] = '0';
    }
    display_game(game);
	return (0);
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

    display_game(&game);
    mlx_hook(game.win, KeyPress, KeyPressMask, &handle_keypress, &game);
    mlx_key_hook(game.win, &handle_exit, &game);
    mlx_loop(game.ptr);
    return (game.ptr);
}