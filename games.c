/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   games.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorin <smorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:00:27 by smorin            #+#    #+#             */
/*   Updated: 2024/03/08 17:07:46 by smorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win_init(t_map *games)
{
	games->mlx_ptr = mlx_init();
	if (!(games->mlx_ptr))
		free_all_and_error(games, "EROOR");
	games->sizex = 0;
	games->sizey = 0;
	mlx_get_screen_size(games->mlx_ptr, &(games->sizex), &(games->sizey));
	if (games->lenght * 32 > games->sizex || games->height * 32 > games->sizey)
	{
		mlx_destroy_display(games->mlx_ptr);
		free(games->mlx_ptr);
		free_all_and_error(games, "Too big");
		exit(0);
	}
	games->win_ptr = mlx_new_window(games->mlx_ptr, games->lenght * 32,
			games->height * 32, "so_long");
	if (!(games->win_ptr))
		free_all_and_error(games, "ERROOR");
}

void	ft_xpms(t_map *games)
{
	games->imgs->collect = mlx_xpm_file_to_image(games->mlx_ptr,
			"./textures/Boss.xpm", &(games->imgs->l), &(games->imgs->h));
	if (!games->imgs->collect)
		exit_point(games);
	games->imgs->exitt = mlx_xpm_file_to_image(games->mlx_ptr,
			"./textures/Exit.xpm", &(games->imgs->l), &(games->imgs->h));
	if (!games->imgs->exitt)
		exit_point(games);
	games->imgs->floorr = mlx_xpm_file_to_image(games->mlx_ptr,
			"./textures/Grass.xpm", &(games->imgs->l), &(games->imgs->h));
	if (!games->imgs->floorr)
		exit_point(games);
	games->imgs->player = mlx_xpm_file_to_image(games->mlx_ptr,
			"./textures/Player.xpm", &(games->imgs->l), &(games->imgs->h));
	if (!games->imgs->player)
		exit_point(games);
	games->imgs->walls = mlx_xpm_file_to_image(games->mlx_ptr,
			"./textures/Wall.xpm", &(games->imgs->l), &(games->imgs->h));
	if (!games->imgs->walls)
		exit_point(games);
}

void	ft_put(t_map *games, void *imgs, int x, int y)
{
	mlx_put_image_to_window(games->mlx_ptr, games->win_ptr, imgs, x * 32, y
		* 32);
}

void	init_image(t_map *games)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (games->maps[y])
	{
		x = 0;
		while (games->maps[y][x])
		{
			if (games->maps[y][x] == '1')
				ft_put(games, games->imgs->walls, x, y);
			else if (games->maps[y][x] == '0')
				ft_put(games, games->imgs->floorr, x, y);
			else if (games->maps[y][x] == 'P')
				ft_put(games, games->imgs->player, x, y);
			else if (games->maps[y][x] == 'E')
				ft_put(games, games->imgs->exitt, x, y);
			else if (games->maps[y][x] == 'C')
				ft_put(games, games->imgs->collect, x, y);
			x++;
		}
		y++;
	}
}
