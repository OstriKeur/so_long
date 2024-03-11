/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorin <smorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:20:12 by smorin            #+#    #+#             */
/*   Updated: 2024/03/08 16:27:05 by smorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef SIZE
#  define SIZE 50
# endif
# define TRUE 1
# define FALSE 0
# define WIN_NAME "so_long"
# define TILE_SIZE 32

typedef struct s_imgs
{
	void	*collect;
	void	*walls;
	void	*player;
	void	*floorr;
	void	*exitt;
	int		h;
	int		l;
}			t_imgs;

typedef struct s_map
{
	t_imgs	*imgs;
	int		height;
	int		lenght;
	int		exit;
	int		spawn;
	int		won;
	int		exit_found;
	int		moves;
	int		start_found;
	char	**maps;
	char	**map;
	char	*files_name;
	int		accessible_collectibles;
	int		exit_accessible;
	int		px_x;
	int		py_y;
	int		fd;
	char	*lines;
	char	*buff;
	int		items_found;
	int		items_nbr;
	void	*mlx_ptr;
	void	*win_ptr;
	int		sizex;
	int		sizey;
}			t_map;

/// Parsing
void		check_name(char *s);
void		parsing_map(t_map *games);
void		init(t_map *games, char *map_file_name);
void		check_closed(t_map *games);
void		check_rectangle(t_map *games);
void		check_start(t_map *games);
void		flood_fill(t_map *games, int y, int x);
void		check_content(t_map *games);
void		check_map_exit(t_map *so_long);
void		check_map_item(t_map *so_long);
void		ft_check_path(t_map *games, int x, int y);
int			ft_copy_map(t_map *games);
void		group_all(t_map *games);

/// Free
void		map_error(char *s);
void		free_all_and_error(t_map *games, char *s);
void		map_error(char *s);
void		free_all(t_map *games);

/// Render map
void		ft_win_init(t_map *games);
void		ft_xpms(t_map *games);
void		ft_put(t_map *games, void *imgs, int x, int y);
void		init_image(t_map *games);
int			controls_working(int command, t_map *games);
int			exit_point(t_map *games);
int			exit_map(t_map *games);

#endif
