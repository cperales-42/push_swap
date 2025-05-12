/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:12:16 by marvin            #+#    #+#             */
/*   Updated: 2025/05/03 16:12:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_target_to_top(t_stack_node **stack, t_stack_node *top_node) //Define a function that moves the required node to the top of the stack
{
    if (*stack == top_node)
        return ;
    while (*stack != top_node) //Check if the required node is not already the first node
    {
            if (top_node->above_median)
                ra(stack, false);
            else
                rra(stack, false);
    }
}

void    ft_sort_three(t_stack_node **stack)
{
    int a = (*stack)->nbr;
    int b = (*stack)->next->nbr;
    int c = (*stack)->next->next->nbr;

    if (a > b && b < c && a < c)
        sa(stack, false); // 2 1 3 -> 1 2 3
    else if (a > b && b > c)
    {
        sa(stack, false); // 3 2 1 -> 2 3 1
        rra(stack, false); // -> 1 2 3
    }
    else if (a > b && b < c && a > c)
        ra(stack, false); // 3 1 2 -> 1 2 3
    else if (a < b && b > c && a < c)
    {
        sa(stack, false); // 1 3 2 -> 3 1 2
        ra(stack, false); // -> 1 2 3
    }
    else if (a < b && b > c && a > c)
        rra(stack, false); // 2 3 1 -> 1 2 3
    // else ya está ordenado (1 2 3)
}

int main(int argc, char **argv)
{
    t_stack_node    *a;
    t_stack_node    *b;

    a = NULL;
    b = NULL;
    if (argc == 1 ||(argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    init_stack_a(&a, argv + 1); //el +1 es pq si no sería el nombre del programa
    if (!stack_sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a, false);
        else if (stack_len(a) == 3)
            ft_sort_three(&a);
        else
            ft_turk(&a, &b);
    }
}