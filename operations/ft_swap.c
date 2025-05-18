/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:18:59 by cperales          #+#    #+#             */
/*   Updated: 2025/05/18 09:59:41 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void swap(t_stack_node **head) //cambia el primer y el segundo elemento de un stack
{
    if (!*head || !(*head)->next)
        return ;
    *head = (*head)->next; //cambia A por B
    (*head)->prev->prev = *head; //ahora el nodo previo de A es B
    (*head)->prev->next = (*head)->next; //ahora el nodo siguiente de A es el siguiente de B (C o null)
    if ((*head)->next)
        (*head)->next->prev = (*head)->prev; //si existe C, el previo de C es A
    (*head)->next = (*head)->prev; //el siguiente de B es A
    (*head)->prev = NULL; // el anterior de B es null
}

void sa(t_stack_node **a, bool print)
{
    swap(a);
    if (!print)
        ft_printf("sa\n");
}

void sb(t_stack_node **b, bool print)
{
    swap(b);
    if (!print)
        ft_printf("sb\n");
}

void ss(t_stack_node **a, t_stack_node **b, bool print)
{
    swap(a);
    swap(b);
    if (!print)
        ft_printf("ss\n");
}
