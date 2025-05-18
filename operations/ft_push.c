/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:14:25 by marvin            #+#    #+#             */
/*   Updated: 2025/05/03 17:14:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void push(t_stack_node **src, t_stack_node **dst) //pushea de un stack a otro
{
    t_stack_node    *push_node; //guarda el puntero al nodo que vamos a pushear

    if (!*src)
        return ;
    push_node = *src; //asignamos el top node a la variable
    *src = (*src)->next; //pasamos el puntero del stack al siguiente nodo, que ahora sera el top node
    if (*src)
        (*src)->prev = NULL; //como ahora es el top node el previo apunta a null
    push_node->prev = NULL; //nos aseguramos de que el nodo que vamos a pushear no este enlazado a nada
    if (!*dst) //comprobamos si el otro stack esta vacio
    {
        *dst = push_node; //si esta vacio metemos el nodo que queremos pushear directamente
        push_node->next = NULL; //lo enlazamos a null ya que no hay mas elementos
    }
    else 
    {
        push_node->next = *dst; //asignamos el nodo que queremos pushear por encima del top node actual
        push_node->next->prev = push_node; //lista doblemente enlazada asi que enlazamos el antiguo top del nuevo stack al nuevo top
        *dst = push_node; //ahora que hemos movido el anterior top metemos el nuevo
    }
}

void pa(t_stack_node **a, t_stack_node **b, bool print) //push a
{
    push(b, a);
    if (!print)
        ft_printf("pa\n");
}

void pb(t_stack_node **b, t_stack_node **a, bool print) // push b
{
    push(a, b);
    if (!print)
        ft_printf("pb\n");
}
