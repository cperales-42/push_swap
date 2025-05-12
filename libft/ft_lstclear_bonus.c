/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:45:08 by cperales          #+#    #+#             */
/*   Updated: 2025/01/13 18:31:10 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ongoing;
	t_list	*tmp;

	ongoing = *lst;
	while (ongoing)
	{
		del(ongoing->content);
		tmp = ongoing;
		ongoing = ongoing->next;
		free(tmp);
	}
	*lst = NULL;
}
