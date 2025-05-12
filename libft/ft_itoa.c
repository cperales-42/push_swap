/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 01:06:50 by cperales          #+#    #+#             */
/*   Updated: 2025/01/13 18:31:02 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int nb)
{
	size_t	cont;

	cont = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		cont++;
	while (nb != 0)
	{
		nb /= 10;
		cont++;
	}
	return (cont);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (!n)
		return (ft_strdup("0"));
	i = ft_count_digits(n);
	res = (char *)ft_calloc((i + 1), sizeof(char));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		n *= (-1);
		res[0] = '-';
	}
	i--;
	while (n > 0)
	{
		res[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (res);
}
