#include "../include/so_long.h"

t_nbr	ft_readnbrs(void *ptr)
{
	t_nbr	nbrs;

	nbrs.n0 = ft_new_sprite(ptr, "nbrs/n0.xpm");
	nbrs.n1 = ft_new_sprite(ptr, "nbrs/n1.xpm");
	nbrs.n2 = ft_new_sprite(ptr, "nbrs/n2.xpm");
	nbrs.n3 = ft_new_sprite(ptr, "nbrs/n3.xpm");
	nbrs.n4 = ft_new_sprite(ptr, "nbrs/n4.xpm");
	nbrs.n5 = ft_new_sprite(ptr, "nbrs/n5.xpm");
	nbrs.n6 = ft_new_sprite(ptr, "nbrs/n6.xpm");
	nbrs.n7 = ft_new_sprite(ptr, "nbrs/n7.xpm");
	nbrs.n8 = ft_new_sprite(ptr, "nbrs/n8.xpm");
	nbrs.n9 = ft_new_sprite(ptr, "nbrs/n9.xpm");
	return (nbrs);
}

int	ft_getnbrs(t_game *game)
{
	game->nbr = ft_readnbrs(game->ptr);
	if (!game->nbr.n0.pointer || !game->nbr.n1.pointer)
		return (0);
	else if (!game->nbr.n2.pointer || !game->nbr.n3.pointer)
		return (0);
	else if (!game->nbr.n4.pointer || !game->nbr.n5.pointer)
		return (0);
	else if (!game->nbr.n6.pointer || !game->nbr.n7.pointer)
		return (0);
	else if (!game->nbr.n8.pointer || !game->nbr.n9.pointer)
		return (0);
	return (1);
}

void	*put_moves(t_nbr nbr, int i)
{
	if (i == 0)
		return (nbr.n0.pointer);
	else if (i == 1)
		return (nbr.n1.pointer);
	else if (i == 2)
		return (nbr.n2.pointer);
	else if (i == 3)
		return (nbr.n3.pointer);
	else if (i == 4)
		return (nbr.n4.pointer);
	else if (i == 5)
		return (nbr.n5.pointer);
	else if (i == 6)
		return (nbr.n6.pointer);
    else if (i == 7)
		return (nbr.n7.pointer);
    else if (i == 8)
		return (nbr.n8.pointer);
	else if (i == 9)
		return (nbr.n9.pointer);
	return (NULL);
}

void	*display_moves(t_game *game, int moves)
{
	int i;
	int	x;
    int nbr;

	i = 3;
	x = 3 * 24 + 7;
    nbr = moves - 1;
	while (i >= 0)
	{
		mlx_put_image_to_window(game->ptr, game->win,
			put_moves(game->nbr, nbr % 10), x, 7);
        x -= 24;
        nbr = nbr / 10;
        i--;
	}
    return (game->ptr);
}