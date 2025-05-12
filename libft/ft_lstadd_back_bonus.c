/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:17:55 by cperales          #+#    #+#             */
/*   Updated: 2025/01/13 18:31:05 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ongoing;

	ongoing = *lst;
	if (*lst)
	{
		while (ongoing->next)
			ongoing = ongoing->next;
		ongoing->next = new;
	}
	else
		*lst = new;
}
