/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:57:01 by nmorandi          #+#    #+#             */
/*   Updated: 2023/03/12 16:03:28 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_max_a(t_list **stack_a, t_list **stack_b)
{
	int	index;

	index = get_max_index((*stack_b));
	if (index == 0)
		push_x('b', stack_a, stack_b);
	else if (index + 1 == ft_lstsize((*stack_a)))
	{
		rev_rotate(stack_b, 'b');
		push_x('b', stack_a, stack_b);
	}
	else
	{
		place_index(stack_b, index, 'b');
		push_x('b', stack_a, stack_b);
	}
}

static void	push_min_a(t_list **stack_a, t_list **stack_b)
{
	int	index;

	index = get_max_index((*stack_b));
	if (index == 0)
	{
		push_x('b', stack_a, stack_b);
		rotate(stack_b, 'b');
	}
	else if (index + 1 == ft_lstsize((*stack_b)))
	{
		rev_rotate(stack_b, 'b');
		push_x('b', stack_a, stack_b);
	}
	else
	{
		place_index(stack_b, index, 'b');
		push_x('b', stack_a, stack_b);
	}
}

int	push_cmd_a(t_list **stack_a, t_list **stack_b)
{
	int	curr;

	curr = *(int *)(*stack_a)->content;
	if (curr > get_minmax_value((*stack_b), 0))
	{
		push_max_a(stack_a, stack_b);
		return (1);
	}
	else if (curr < get_minmax_value((*stack_b), 1))
	{
		push_min_a(stack_a, stack_b);
		return (1);
	}
	return (0);
}
