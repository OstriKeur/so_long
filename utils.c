/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorin <smorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:52:26 by smorin            #+#    #+#             */
/*   Updated: 2024/03/07 18:50:46 by smorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_name(char *s)
{
	int	l;

	l = ft_strlen(s) - 1;
	if (s[l] == 'r' && s[l - 1] == 'e' && s[l - 2] == 'b' && s[l - 3] == '.')
		return ;
	map_error("ITS NOT .BER BITCH");
}

void	init(t_map *games, char *map_file_name)
{
	games->files_name = map_file_name;
	games->items_found = 0;
	games->items_nbr = 0;
	games->exit = FALSE;
	games->won = FALSE;
	games->exit_found = 0;
	games->moves = 0;
	games->start_found = 0;
	games->accessible_collectibles = 0;
	games->exit_accessible = FALSE;
}

void	flood_fill(t_map *games, int x, int y)
{
	if (games->map[y][x] == '1')
		return ;
	if (games->map[y][x] == 'E')
	{
		games->exit_found = 1;
		return ;
	}
	if (games->map[y][x] == 'C')
		games->items_found++;
	games->map[y][x] = '1';
	if (games->map[y][x + 1] != '1')
		flood_fill(games, x + 1, y);
	if (games->map[y][x - 1] != '1')
		flood_fill(games, x - 1, y);
	if (games->map[y + 1][x] != '1')
		flood_fill(games, x, y + 1);
	if (games->map[y - 1][x] != '1')
		flood_fill(games, x, y - 1);
}

int	ft_copy_map(t_map *games)
{
	int	i;

	i = 0;
	games->items_found = 0;
	games->exit_found = 0;
	games->map = ft_calloc((games->height + 1), sizeof(char *));
	if (!games->map)
		return (0);
	while (i < games->height)
	{
		games->map[i] = ft_strdup(games->maps[i]);
		if (!games->map[i])
		{
			ft_free_double_tab(&games->map);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_check_path(t_map *games, int x, int y)
{
	games->px_x = x;
	games->py_y = y;
	if (!ft_copy_map(games))
		free_all_and_error(games, "ERROR");
	flood_fill(games, games->px_x, games->py_y);
	ft_free_double_tab(&games->map);
	if (games->exit_found != 1 || games->items_found != games->items_nbr)
	{
		free_all(games);
	}
}
