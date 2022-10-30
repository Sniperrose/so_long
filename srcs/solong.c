#include "../include/so_long.h"

void    *ft_endgame(t_game *game)
{
    int i;
    int j;

    i = 1;
    while (game->map[i + 1] != NULL)
    {
        j = 1;
        while (game->map[i][j + 1] != '\0')
        {
            game->map[i][j] = '0';
            j++;
        }
        i++;
    }
    i = (int)ft_splitsize(game->map) / 2;
    j = (int)ft_strlen(game->map[0]) / 2;
    game->map[i][j - 1] = 'e';
    game->map[i][j] = 'n';
    game->map[i][j + 1] = 'd';
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
    t_vector    pos;
    int         i;

    i = 0;
    pos = get_pos_player(game->map);

    if (keysym == XK_d || keysym == XK_D)
        i = can_i_move_right(game, pos);
    else    if (keysym == XK_W || keysym == XK_w)
        i = can_i_move_up(game, pos);
    else    if (keysym == XK_A || keysym == XK_a)
        i = can_i_move_left(game, pos);
    else    if (keysym == XK_S || keysym == XK_s)
        i = can_i_move_down(game, pos);
    else    if (keysym == XK_Escape)
        mlx_destroy_window(game->ptr, game->win);
    if (i == -1)
        ft_endgame(game);
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
    mlx_loop(game.ptr);
    return (game.ptr);
}