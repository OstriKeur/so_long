/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:36:40 by wscherre          #+#    #+#             */
/*   Updated: 2024/02/09 20:46:24 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_next_line(int fd)
{
	static char	statik[4095][BUFFER_SIZE + 1];
	char		*fourre_merde;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	fourre_merde = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!fourre_merde)
		return (NULL);
	ft_memcpy(fourre_merde, statik[fd], ft_strlen(statik[fd]));
	fourre_merde[ft_strlen(statik[fd])] = '\0';
	if (!statik[fd][0])
		fourre_merde[0] = '\0';
	line = ft_fill_line(fd, &fourre_merde);
	if (!line)
	{
		if (fourre_merde)
			(free(fourre_merde), fourre_merde = NULL);
		return (NULL);
	}
	ft_memcpy(statik[fd], fourre_merde, ft_strlen(fourre_merde));
	statik[fd][ft_strlen(fourre_merde)] = '\0';
	(free(fourre_merde), fourre_merde = NULL);
	return (line);
}

/* #include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*str;
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd = open("../test.txt", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		printf("gnl : '%s'", str);
		free(str);
	}
	free(str);
} */
/* #include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	fd1 = open("test/test.txt", O_RDONLY);
	fd2 = open("test/text.txt", O_RDONLY);
	fd3 = open("tests/bible.txt", O_RDONLY);
	i = 1;
	while (i < 100183)
	{
		line = get_next_line(fd1);
		printf("line %d :%s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line %d :%s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line %d :%s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
 */
