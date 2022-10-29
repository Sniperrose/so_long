#include "../include/so_long.h"

int handle_exit(int keysym, t_game *game)
{
    if (keysym == XK_Escape)
        mlx_destroy_window(game->ptr, game->win);
    return (0);
}

void    *ft_endgame(t_game *game)
{
    mlx_destroy_window(game->ptr, game->win);
    return (NULL);
}

void ft_printmap(char **map)
{
    int i = 0;
    while (map[i])
    {   
        printf("%s\n", map[i]);
        i++;    
    }
}

int	handle_keypress(int keysym, t_game *game)
{
    t_vector pos;

    pos = get_pos_player(game->map);
    if (keysym == XK_d || keysym == XK_D)
    {
        if (can_i_move_right(game, pos) == -1)
            ft_endgame(game);
    }
    else    if (keysym == XK_W || keysym == XK_w)
    {
        if (can_i_move_up(game, pos) == -1)
            ft_endgame(game);
    }
    else    if (keysym == XK_A || keysym == XK_a)
    {
        if (can_i_move_left(game, pos) == -1)
            ft_endgame(game);
    }
    else    if (keysym == XK_S || keysym == XK_s)
    {
        if (can_i_move_down(game, pos) == -1)
            ft_endgame(game);
    }
    ft_printmap(game->map);
    printf("collectible: %d\n", game->collectible);
    display_game(game, game->type);
	return (0);
}
void    *solong(t_game game)
{
    game.collectible = ft_mapcheck(game.map);
    if (!game.collectible)
        return (NULL);
    game.type = 0;
    game.x = ((int)ft_strlen(game.map[0])) * res;
    game.y = ((int)ft_splitsize(game.map)) * res;
    game.ptr = mlx_init();
    game.win = mlx_new_window(game.ptr, game.x, game.y, "so_long_test");

    display_game(&game, game.type);
    mlx_hook(game.win, KeyPress, KeyPressMask, &handle_keypress, &game);
    mlx_key_hook(game.win, &handle_exit, &game);
    mlx_loop(game.ptr);
    return (game.ptr);
}