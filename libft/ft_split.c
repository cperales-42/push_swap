/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 05:51:34 by cperales          #+#    #+#             */
/*   Updated: 2025/01/13 18:32:02 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **s, int i)
{
	while (i)
		free(s[--i]);
	free(s);
	return (NULL);
}

static int	ft_word_length(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	ft_chrcounter(const char *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			cont++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (cont);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc((ft_chrcounter(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			res[j] = ft_substr(s + i, 0, ft_word_length(s + i, c));
			if (!res[j])
				return (ft_free(res, j));
			j++;
			i += ft_word_length(s + i, c);
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}
