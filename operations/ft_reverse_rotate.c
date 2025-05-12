/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:10:19 by cperales          #+#    #+#             */
/*   Updated: 2025/05/05 17:32:45 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void reverse_rotate(t_stack_node **stack) //manda el ultimo elemento arriba
{
    t_stack_node    *last_node;
    if (!*stack || (*stack)->next)
        return ;
    last_node = find_last(*stack);
    last_node->prev->next = NULL; //el penultimo que apuntaba al ultimo ahora es el ultimo y apunta a null
    last_node->next = *stack; //hacemos que apunte al antiguo primero, convirtiendo este en el primero
    last_node->prev = NULL; //el nuevo primero apunta a null
    *stack = last_node; //efectuamos la rotacion
    last_node->next->prev = last_node; //hacemos que el nuevo segundo apunte al nuevo primero
}

void    rra(t_stack_node **a, bool print)
{
    reverse_rotate(a);
    if (!print)
        ft_printf("rra\n");
}

void    rrb(t_stack_node **b, bool print)
{
    reverse_rotate(b);
    if (!print)
        ft_printf("rrb\n");
}

void    rrr(t_stack_node **a, t_stack_node **b, bool print)
{
    reverse_rotate(a);
    reverse_rotate(b);
    if (!print)
        ft_printf("rrr\n");
}