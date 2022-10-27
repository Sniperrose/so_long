#include "../include/so_long.h"

t_vector get_pos_player(char **map)
{
    t_vector pos;

    pos.y = 0;
    while (map[pos.y] != NULL)
    {
        pos.x = 0;
        while (map[pos.y][pos.x] != '\0')
        {
            if (map[pos.y][pos.x] == 'P')
                return (pos);
            pos.x++;
        }
        pos.y++;
    }
    return (pos);
}

int can_i_move_right(t_game *game, int x, int y)
{
    if (game->map[y][x + 1] == '1')
        return (0);
    else if (game->map[y][x + 1] == 'C')
    {
        game->collectible -= 1;
        return (1); 
    }
    else if (game->map[y][x + 1] == 'E')
    {
        if (game->collectible == 0)
            return (2);
        else
            return (0);
    }
    return (1);
}


int can_i_move_left(t_game *game, int x, int y)
{
    if (game->map[y][x - 1] == '1')
        return (0);
    else if (game->map[y][x - 1] == 'C')
    {
        game->collectible -= 1;
        return (1); 
    }
    else if (game->map[y][x - 1] == 'E')
    {
        if (game->collectible == 0)
            return (2);
        else
            return (0);
    }
    return (1);
}

int can_i_move_up(t_game *game, int x, int y)
{
    if (game->map[y - 1][x] == '1')
        return (0);
    else if (game->map[y - 1][x] == 'C')
    {
        game->collectible -= 1;
        return (1); 
    }
    else if (game->map[y - 1][x] == 'E')
    {
        if (game->collectible == 0)
            return (2);
        else
            return (0);
    }
    return (1);
}

int can_i_move_down(t_game *game, int x, int y)
{
    if (game->map[y + 1][x] == '1')
        return (0);
    else if (game->map[y + 1][x] == 'C')
    {
        game->collectible -= 1;
        return (1); 
    }
    else if (game->map[y + 1][x] == 'E')
    {
        if (game->collectible == 0)
            return (2);
        else
            return (0);
    }
    return (1);
}