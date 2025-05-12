/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:50:56 by cperales          #+#    #+#             */
/*   Updated: 2025/05/05 17:32:44 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void rotate(t_stack_node **stack) //manda el primer elemento al fondo
{
    t_stack_node    *last_node;
    if (!*stack || (*stack)->next)
        return ;
    last_node = find_last(*stack);
    last_node->next = *stack; //el ultimo anterior pasa a apuntar al stack que rotamos como el nuevo ultimo
    *stack = (*stack)->next; //como hemos rotado, hacemos que el primero del stack pase a ser el que antes era segundo
    (*stack)->prev = NULL; //el antiguo segundo y ahora primero pasa a apuntar a null como previo
    last_node->next->prev = last_node; //el anterior del nuevo ultimo apunta al ultimo anterior
    last_node->next->next = NULL; //el nuevo ultimo apunta a null
}

void    ra(t_stack_node **a, bool print)
{
    rotate(a);
    if (!print)
        ft_printf("ra\n");
}

void    rb(t_stack_node **b, bool print)
{
    rotate(b);
    if (!print)
        ft_printf("rb\n");
}

void    rr(t_stack_node **a, t_stack_node **b, bool print)
{
    rotate(a);
    rotate(b);
    if (!print)
        ft_printf("rr\n");
}