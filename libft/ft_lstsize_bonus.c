/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:07:21 by cperales          #+#    #+#             */
/*   Updated: 2025/01/13 18:31:23 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ongoing;
	int		i;

	ongoing = lst;
	i = 0;
	while (ongoing)
	{
		i++;
		ongoing = ongoing->next;
	}
	return (i);
}
