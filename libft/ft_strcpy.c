/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:23:36 by wscherre          #+#    #+#             */
/*   Updated: 2024/02/09 23:02:16 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcpy(char *dest, const char *src)
{
	size_t	i;
	size_t	sizesrc;

	i = 0;
	sizesrc = 0;
	while (src[sizesrc])
		sizesrc++;
	if (sizesrc < 1)
		return (sizesrc);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (sizesrc);
}
