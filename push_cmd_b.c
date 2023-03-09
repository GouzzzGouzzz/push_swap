/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:46:31 by gouz              #+#    #+#             */
/*   Updated: 2023/03/09 17:51:23 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_max_b(t_list **stack_a, t_list **stack_b)
{
	int index;

	index = get_max_index((*stack_a));
	if (index == 0)
	{
		rotate(stack_a, 'a');
		push_x('a',stack_a, stack_b);
	}
	else if (index + 1 == ft_lstsize((*stack_a)))
	{
		push_x('a',stack_a, stack_b);
		rotate(stack_a, 'a');
	}
	else
	{
		place_index(stack_a, index + 1, ft_lstsize((*stack_a)), 'a');
		push_x('a',stack_a, stack_b);
	}
}

static void	push_min_b(t_list **stack_a, t_list **stack_b)
{
	int index;

	index = get_min_index((*stack_a));
	if (index == 0)
		push_x('a',stack_a, stack_b);
	else if (index + 1 == ft_lstsize((*stack_a)))
	{
		rev_rotate(stack_a, 'a');
		push_x('a',stack_a, stack_b);
	}
	else
	{
		place_index(stack_a, index, ft_lstsize((*stack_a)), 'a');
		push_x('a',stack_a, stack_b);
	}
}

int	push_cmd_b(t_list **stack_a, t_list **stack_b)
{
	int curr;

	curr = *(int *)(*stack_b)->content;
	if (curr > get_minmax_value((*stack_a), 0))
	{
		//printf("ENTERING MAX\n");
		push_max_b(stack_a, stack_b);
		return (1);
	}
	else if (curr < get_minmax_value((*stack_a), 1))
	{
		//printf("ENTERING MIN\n");
		push_min_b(stack_a, stack_b);
		return (1);
	}
	//printf("LEAVING CMD B\n");
	return (0);
}
