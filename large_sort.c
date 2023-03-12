/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:12:28 by gouz              #+#    #+#             */
/*   Updated: 2023/03/12 16:09:50 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	push_first(t_list **stack, t_list **stack_b)
{
	int	to_push;

	to_push = 2;
	while (ft_lstsize((*stack)) > 3 && to_push-- > 0)
		push_x('b', stack, stack_b);
	if (ft_lstsize(*stack_b) == 2)
		if (*(int *)(*stack_b)->content < *(int *)(*stack_b)->next->content)
			swap(stack_b, 'b');
}

void	sort_three(t_list **stack)
{
	if (get_min_index((*stack)) == 0)
	{
		rev_rotate(stack, 'a');
		swap(stack, 'a');
	}
	else if (get_max_index((*stack)) == 0)
	{
		rotate(stack, 'a');
		if (already_sorted((*stack)) != -1)
			swap(stack, 'a');
	}
	else
	{
		if (get_max_index((*stack)) == 1)
			rev_rotate(stack, 'a');
		else
			swap(stack, 'a');
	}
}

static void	b_to_a(t_list **stack, t_list **stack_b)
{
	int	nb;
	int	curr;
	int	ret;

	ret = 0;
	while ((*stack_b))
	{
		nb = *(int *)(*stack_b)->content;
		curr = *(int *)(*stack)->content;
		ret = push_cmd_b(stack, stack_b);
		if (ret != 1)
		{
			if (curr > nb && *(int *)ft_lstlast((*stack))->content < nb)
				push_x('a', stack, stack_b);
			else
				place_index(stack, find_pos_to_a((*stack), nb), 'a');
		}
	}
}

static void	a_to_b(t_list **stack, t_list **stack_b)
{
	int	curr;
	int	first_b;
	int	ret;

	ret = 0;
	while (ft_lstsize(*(stack)) > 3 && already_sorted((*stack)))
	{
		curr = *(int *)(*stack)->content;
		first_b = *(int *)(*stack_b)->content;
		ret = push_cmd_a(stack, stack_b);
		if (ret != 1)
		{
			if (curr > first_b)
				push_x('b', stack, stack_b);
			else
			{
				if (calculated_push(stack, stack_b) == -1)
					place_index(stack_b, find_pos_to_b((*stack_b), curr), 'b');
			}
		}
	}
}

int	large_sort(t_list **stack, t_list **stack_b)
{
	if (ft_lstsize((*stack)) == 5)
	{
		push_first(stack, stack_b);
		if (already_sorted((*stack)) != -1)
			sort_three(stack);
		b_to_a(stack, stack_b);
		place_index(stack, get_min_index(*stack), 'a');
		return (1);
	}
	push_first(stack, stack_b);
	a_to_b(stack, stack_b);
	place_index(stack_b, get_max_index(*stack_b), 'b');
	//print_list((*stack_b));
	if (already_sorted(*stack) != -1 && ft_lstsize(*stack))
		sort_three(stack);
	//printf("tri\n");
	//print_list((*stack));
	b_to_a(stack, stack_b);
	place_index(stack, get_min_index(*stack), 'a');
	//print_list((*stack));
}
