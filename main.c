/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorin <smorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:01:05 by smorin            #+#    #+#             */
/*   Updated: 2024/03/04 18:08:20 by smorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_content(t_map *games)
{
	((check_rectangle(games)), (check_start(games)));
	((check_closed(games)), (check_map_exit(games)));
	check_map_item(games);
	ft_check_path(games, games->px_x, games->py_y);
	if (games->exit_found != 1)
		free_all_and_error(games, "NOT EXIT FOUND");
	if (games->items_found != games->items_nbr)
		free_all_and_error(games, "NOT COLLECT ALL ITEM");
}

int	main(int ac, char **av)
{
	t_map	games;

	if (ac == 2)
	{
		check_name(av[1]);
		init(&games, av[1]);
		parsing_map(&games);
		check_content(&games);
		ft_win_init(&games);
		init_image(&games);
		mlx_hook(games.win_ptr, KeyRelease, KeyReleaseMask, &controls_working,
			&games);
		mlx_hook(games.win_ptr, DestroyNotify, 0L, &exit_point, &games);
		mlx_loop(games.mlx_ptr);
	}
	if (ac == 1)
		map_error("NOT MAP FOUND");
	else if (ac > 2)
		map_error("TOO MANY ARGUMENTS");
}
