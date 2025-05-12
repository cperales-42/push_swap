/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:41:14 by cperales          #+#    #+#             */
/*   Updated: 2025/05/12 00:12:48 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void ft_move_a_to_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest; //variable para reducir complejidad

    cheapest = ft_get_cheapest(*a);
    while (*a != cheapest && *b != cheapest->target_node
        && cheapest->above_median && cheapest->target_node->above_median) // rotamos ambos mientras no estén arriba y están en la misma mitad
        rr(a, b, false); //rotar ambos
    while (*a != cheapest && *b != cheapest->target_node
        && !cheapest->above_median && !cheapest->target_node->above_median)
        rrr(a, b, false); //hacer reverse rotate en ambos
    ft_move_node_to_top(a, 'A'); //encontramos el más barato de A y lo subimos al top
    if (cheapest->target_node->prev) //si el nodo objetivo del cheapest tiene previo (lo que significa que no está en la cima)
        ft_move_node_to_top(b, 'B'); //lo movemos hasta la cima
    pb(b, a, false); //lo pusheamos a B
}

void ft_move_b_to_a(t_stack_node **a, t_stack_node **b)
{
    ft_target_to_top(a, (*b)->target_node);
    pa(a, b, false); //lo pusheamos a A
}

void    ft_turk(t_stack_node **a, t_stack_node **b)
{
    int len_a; //para reducir la complejidad de la funcion

    len_a = stack_len(*a);
    while (len_a-- > 3 && stack_len(*b) < 2 && !stack_sorted(*a)) //nos aseguramos de que B tenga 2 nodos
        pa(a,b,false);
    while (len_a-- > 3 && !stack_sorted(*a)) //hasta que en a solo hayan 3 
    {
            ft_link_a_to_b(*a, *b); //linkeamos A a B
            ft_move_a_to_b(a, b); //movemos el mas barato de A hasta B
            len_a--;
    }
    ft_sort_three(a); //ordenamos los 3 existentes
    while (*b) //mientras haya algo en el stack de b
    {
        ft_printf("Processing node in B: %d\n", (*b)->nbr);
        ft_link_b_to_a(*a, *b); //linkeamos B a A
        ft_move_b_to_a(a, b); //movemos el mas barato de B hasta A
    }
    ft_current_index(*a);
    ft_target_to_top(a, find_min(*a));
}   
