/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorin <smorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:28:54 by smorin42          #+#    #+#             */
/*   Updated: 2024/03/04 18:00:20 by smorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	parsing(t_map *games)
{
	int	height;

	games->buff = ft_get_next_line(games->fd);
	height = 0;
	games->lines = NULL;
	while (games->buff)
	{
		games->lines = ft_strjoin(games->lines, games->buff);
		free(games->buff);
		games->buff = ft_get_next_line(games->fd);
	}
	games->maps = ft_split(games->lines, '\n');
	free(games->lines);
	if (!games->maps)
		free_all_and_error(games, "MALLOC ERROR");
	if (!games->maps[0])
		free_all_and_error(games, "TOO MUCH LINES");
	close(games->fd);
	while (games->maps[height] != NULL)
		height++;
	games->height = height;
	games->lenght = ft_strlen(games->maps[0]);
	if (games->height == 0)
		free_all_and_error(games, "EMPTY MAP FILE");
}

void	parsing_map(t_map *games)
{
	games->fd = open(games->files_name, O_RDONLY);
	if (games->fd < 0)
		map_error("NO MAP SO SORRY BRO");
	parsing(games);
}
