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
}

int can_i_move_left(t_game *game, t_vector pos)
{
    if (game->map[pos.y][pos.x - 1] == '0')
    {
        game->type = 1;
        ft_do_move(game, pos, 'A');
        return (1);
    }
    else if (game->map[pos.y][pos.x - 1] == 'C')
    {
        game->type = 1;
        game->collectible -= 1;
        ft_do_move(game, pos, 'A');
        return (1);
    }
    else if (game->map[pos.y][pos.x - 1] == 'E')
    {
        if (game->collectible == 0)
        {
            game->map[pos.y][pos.x] = '0';
            return (-1);
        }
    }
    return (0);
}

int can_i_move_right(t_game *game, t_vector pos)
{
    if (game->map[pos.y][pos.x + 1] == '0')
    {
        game->type = 0;
        ft_do_move(game, pos, 'D');
        return (1);
    }
    else if (game->map[pos.y][pos.x + 1] == 'C')
    {
        game->type = 0;
        game->collectible -= 1;
        ft_do_move(game, pos, 'D');
        return (1);
    }
    else if (game->map[pos.y][pos.x + 1] == 'E')
    {
        if (game->collectible == 0)
        {
            game->map[pos.y][pos.x] = '0';
            return (-1);
        }
    }
    return (0);
}

int can_i_move_up(t_game *game, t_vector pos)
{
    if (game->map[pos.y - 1][pos.x] == '0')
    {
        game->type = 1;
        ft_do_move(game, pos, 'W');
        return (1);
    }
    else if (game->map[pos.y - 1][pos.x] == 'C')
    {
        game->type = 1;
        game->collectible -= 1;
        ft_do_move(game, pos, 'W');
        return (1);
    }
    else if (game->map[pos.y - 1][pos.x] == 'E')
    {
        if (game->collectible == 0)
        {
            game->map[pos.y][pos.x] = '0';
            return (-1);
        }
    }
    return (0);
}

int can_i_move_down(t_game *game, t_vector pos)
{
    if (game->map[pos.y + 1][pos.x] == '0')
    {
        game->type = 1;
        ft_do_move(game, pos, 'S');
        return (1);
    }
    else if (game->map[pos.y + 1][pos.x] == 'C')
    {
        game->type = 1;
        game->collectible -= 1;
        ft_do_move(game, pos, 'S');
        return (1);
    }
    else if (game->map[pos.y + 1][pos.x] == 'E')
    {
        if (game->collectible == 0)
        {
            game->map[pos.y][pos.x] = '0';
            return (-1);
        }
    }
    return (0);
}
