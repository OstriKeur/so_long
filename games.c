/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   games.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorin42 <smorin42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:00:27 by smorin            #+#    #+#             */
/*   Updated: 2024/03/03 19:19:18 by smorin42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win_init(t_map *games)
{
	games->mlx_ptr = mlx_init();
	if (!(games->mlx_ptr))
		free_all_and_error(games, "EROOR");
	games->win_ptr = mlx_new_window(games->mlx_ptr, games->lenght * TILE_SIZE,
			games->height * TILE_SIZE, "so_long");
	if (!(games->win_ptr))
		free_all_and_error(games, "ERROOR");
}
void	ft_xpms(t_map *games)
{

	games->imgs.COLLECTS = mlx_xpm_file_to_image(games->mlx_ptr, "./textures/Boss.xpm",
			&(games->imgs.l), &(games->imgs.h));
	games->imgs.EXITT = mlx_xpm_file_to_image(games->mlx_ptr, "./textures/Female.xpm",
			&(games->imgs.l), &(games->imgs.h));
	games->imgs.FLOORR = mlx_xpm_file_to_image(games->mlx_ptr, "./textures/Grass.xpm",
			&(games->imgs.l), &(games->imgs.h));
	games->imgs.PLAYER = mlx_xpm_file_to_image(games->mlx_ptr, "./textures/Player.xpm",
			&(games->imgs.l), &(games->imgs.h));
	games->imgs.WALLS = mlx_xpm_file_to_image(games->mlx_ptr, "./textures/Wall.xpm",
			&(games->imgs.l), &(games->imgs.h));
}
void	ft_put(t_map *games, void *imgs, int x, int y)
{
	mlx_put_image_to_window(games->mlx_ptr, games->win_ptr, imgs, x * 32, y
		* 32);
}
void	init_image(t_map *games)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_xpms(games);
	while (games->maps[y])
	{
		x = 0;
		while (games->maps[y][x])
		{
			if (games->maps[y][x] == '1')
				ft_put(games, games->imgs.WALLS, x, y);
			else if (games->maps[y][x] == '0')
				ft_put(games, games->imgs.FLOORR, x, y);
			else if (games->maps[y][x] == 'P')
				ft_put(games, games->imgs.PLAYER, x, y);
			else if (games->maps[y][x] == 'E')
				ft_put(games, games->imgs.EXITT, x, y);
			else if (games->maps[y][x] == 'C')
				ft_put(games, games->imgs.COLLECTS, x, y);
			x++;
		}
		y++;
	}
	// while (games->map[y])
	// {
	// 	ft_printf("%s\n", games->map[y]);
	// 	y++;
	// }
	// exit(1);
}
