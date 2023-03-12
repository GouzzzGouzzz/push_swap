/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:56:59 by gouz              #+#    #+#             */
/*   Updated: 2023/03/12 16:09:56 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos_to_a(t_list *stack, int nb)
{
	int	index;
	int	prev;
	int	next;

	prev = *(int *)stack->content;
	next = *(int *)stack->next->content;
	index = 1;
	if (prev > nb && *(int *)ft_lstlast(stack)->content < nb)
		return (0);
	while (stack->next)
	{
		prev = *(int *)stack->content;
		next = *(int *)stack->next->content;
		if (prev < nb && nb < next)
			return (index);
		index++;
		stack = stack->next;
	}
	return (-1);
}

int	find_pos_to_b(t_list *stack, int nb)
{
	int	index;
	int	prev;
	int	next;

	prev = *(int *)stack->content;
	next = *(int *)stack->next->content;
	index = 1;
	if (prev < nb && *(int *)ft_lstlast(stack)->content > nb)
		return (0);
	while (stack->next)
	{
		prev = *(int *)stack->content;
		next = *(int *)stack->next->content;
		if (prev > nb && nb > next)
			return (index);
		index++;
		stack = stack->next;
	}
	return (-1);
}

int	calculated_push(t_list **stack_a, t_list **stack_b)
{
	int	first;
	int	second;
	int	last;

	first = find_pos_to_b((*stack_b), *(int *)(*stack_a)->content);
	second = find_pos_to_b((*stack_b), *(int *)(*stack_a)->next->content);
	last = find_pos_to_b((*stack_b), *(int *)ft_lstlast(*stack_a)->content);
	if (first == 0)
	{
		push_x('b',stack_a, stack_b);
		return (1);
	}
	else if (second < last && second < first)
	{
		rotate(stack_a, 'a');
		place_index(stack_b, second, 'b');
		push_x('b',stack_a, stack_b);
		return (1);
	}
	else if (last < second && last < first)
	{
		rev_rotate(stack_a, 'a');
		place_index(stack_b, last, 'b');
		push_x('b',stack_a, stack_b);
		return (1);
	}
	return (-1);
}
