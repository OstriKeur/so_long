/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorin <smorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:35:57 by smorin42          #+#    #+#             */
/*   Updated: 2024/03/04 18:34:07 by smorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_closed(t_map *games)
{
	int	x;
	int	y;

	x = 0;
	while (games->maps[x])
	{
		y = 0;
		if (x == 0 || x == games->height - 1)
		{
			while (games->maps[x][y])
			{
				if (games->maps[x][y++] != '1')
					free_all_and_error(games, "Map is not closed");
			}
		}
		else
		{
			if (games->maps[x][0] != '1' || games->maps[x][games->lenght
				- 1] != '1')
				free_all_and_error(games, "Map is not closed");
		}
		x++;
	}
}

void	check_rectangle(t_map *games)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(games->maps[0]);
	while (games->maps[i])
	{
		games->lenght = ft_strlen(games->maps[i++]);
		if (j != games->lenght)
			free_all_and_error(games, "IS NOT RECTANGLE BG");
	}
}

void	check_map_exit(t_map *so_long)
{
	int	i;
	int	j;
	int	exit_flag;

	i = 0;
	exit_flag = 0;
	while (so_long->maps[i])
	{
		j = 0;
		while (so_long->maps[i][j])
		{
			if (so_long->maps[i][j] == 'E')
				exit_flag++;
			if (so_long->maps[i][j] != 'E' && so_long->maps[i][j] != '0'
				&& so_long->maps[i][j] != '1' && so_long->maps[i][j] != 'C'
				&& so_long->maps[i][j] != 'P')
				free_all_and_error(so_long, "Map have wrong char");
			j++;
		}
		i++;
	}
	if (exit_flag != 1)
		free_all_and_error(so_long, "Map doesn't have exactly 1 exit");
}

void	check_map_item(t_map *so_long)
{
	int	i;
	int	j;
	int	item_flag;

	i = 0;
	item_flag = 0;
	so_long->items_nbr = 0;
	while (so_long->maps[i])
	{
		j = 0;
		while (so_long->maps[i][j])
		{
			if (so_long->maps[i][j] == 'C')
			{
				item_flag++;
				so_long->items_nbr++;
			}
			j++;
		}
		i++;
	}
	if (item_flag < 1)
		free_all_and_error(so_long, "Map doesn't have at least 1 item");
}

void	check_start(t_map *games)
{
	int	x;
	int	y;

	x = 0;
	while (games->maps[x])
	{
		y = 0;
		while (games->maps[x][y])
		{
			if (games->maps[x][y] == 'P')
			{
				games->py_y = x;
				games->px_x = y;
				games->start_found++;
			}
			y++;
		}
		x++;
	}
	if (games->start_found != 1)
		free_all_and_error(games, "I NEED 1 START");
}
