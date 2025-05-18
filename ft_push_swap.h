/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperales <cperales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:49:39 by cperales          #+#    #+#             */
/*   Updated: 2025/05/18 09:45:34 by cperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
    int             nbr;
    int             index;
    int             push_cost;
    bool             above_median;
    bool            cheapest;
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
} t_stack_node;

t_stack_node	*find_last(t_stack_node *stack);
int	    stack_len(t_stack_node *stack);
bool	stack_sorted(t_stack_node *stack);

void    pa(t_stack_node **a, t_stack_node **b, bool print);
void    pb(t_stack_node **b, t_stack_node **a, bool print);

void    sa(t_stack_node **a, bool print);
void    sb(t_stack_node **b, bool print);
void    ss (t_stack_node **a, t_stack_node **b, bool print);

void    ra(t_stack_node **a, bool print);
void    rb(t_stack_node **b, bool print);
void    rr(t_stack_node **a, t_stack_node **b, bool print);

void    rra(t_stack_node **a, bool print);
void    rrb(t_stack_node **b, bool print);
void    rrr(t_stack_node **a, t_stack_node **b, bool print);

int ft_syntax_error(char *str);
int ft_duplicate_error(t_stack_node *a, int n);
void    free_stack(t_stack_node **stack);
void    free_errors(t_stack_node **a);

void    init_stack_a(t_stack_node **a, char **argv);
void    ft_sort_three(t_stack_node **stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

void    ft_current_index(t_stack_node *stack);
void    ft_set_target_a(t_stack_node *a, t_stack_node *b);
void    ft_set_cheapest(t_stack_node *stack);
void    ft_link_a_to_b(t_stack_node *a, t_stack_node *b);

void    ft_set_target_a(t_stack_node *a, t_stack_node *b);
void    ft_link_b_to_a(t_stack_node *a, t_stack_node *b);
t_stack_node    *ft_get_cheapest(t_stack_node *a);
void ft_move_node_to_top(t_stack_node **stack, char stackName);

void    ft_turk(t_stack_node **a, t_stack_node **b);
void	ft_target_to_top(t_stack_node **stack, t_stack_node *top_node, char stackName);

#endif