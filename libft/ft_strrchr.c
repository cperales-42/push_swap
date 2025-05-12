/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:42:38 by cperales          #+#    #+#             */
/*   Updated: 2025/01/13 18:32:33 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	find;
	int		i;

	find = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == find)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (NULL);
}
