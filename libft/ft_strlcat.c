/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:27:40 by cperales          #+#    #+#             */
/*   Updated: 2025/01/13 18:32:15 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_length;
	size_t	i;
	size_t	dst_length;

	src_length = 0;
	i = 0;
	dst_length = 0;
	while (dst[dst_length] != '\0')
		dst_length++;
	while (src[src_length] != '\0')
		src_length++;
	if (size <= dst_length)
		return (size + src_length);
	while (i < (size - dst_length - 1) && src[i] != '\0')
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = '\0';
	return (dst_length + src_length);
}
