/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorin <smorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:24:24 by smorin            #+#    #+#             */
/*   Updated: 2024/03/05 16:59:52 by smorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		(free(tab[i]), i++);
	free(tab);
}

void	free_all_and_error(t_map *games, char *s)
{
	free_all(games);
	if (!s)
		exit(1);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(s, 2);
	exit(1);
}

void	map_error(char *s)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(s, 2);
	exit(1);
}

void	free_all(t_map *games)
{
	if (games)
	{
		if (games->maps)
			ft_free_double_tab(&games->maps);
	}
}
