/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorin <smorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:28:54 by smorin42          #+#    #+#             */
/*   Updated: 2024/03/02 19:39:55 by smorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsing_map(t_map *games)
{
	int		fd;
	char	*lines;
	char	*buff;
	int		height;

	fd = open(games->files_name, O_RDONLY);
	if (fd < 0)
		map_error("NO MAP SO SORRY BRO");
	buff = ft_get_next_line(fd);
	height = 0;
	lines = NULL;
	while (buff)
	{
		lines = ft_strjoin(lines, buff);
		free(buff);
		buff = ft_get_next_line(fd);
	}
	games->maps = ft_split(lines, '\n');
	if (!games->maps)
		free_all_and_error(games, "MALLOC ERROR");
	if (!games->maps[0])
		free_all_and_error(games, "TOO MUCH LINES");
	close(fd);
	while (games->maps[height] != NULL)
		height++;
	games->height = height;
	games->lenght = ft_strlen(games->maps[0]);
	if (games->height == 0)
		free_all_and_error(games, "EMPTY MAP FILE");
}
