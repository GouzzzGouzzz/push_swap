/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:56:59 by gouz              #+#    #+#             */
/*   Updated: 2023/03/11 23:33:08 by gouz             ###   ########.fr       */
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

void	calculated_push(t_list **stack_a, t_list **stack_b)
{
	int	first;
	int	second;
	int	last;

	last = 1;
	second = 1;

	first = find_pos_to_b((*stack_b), *(int *)(*stack_a)->content);
	second += find_pos_to_b((*stack_b), *(int *)(*stack_a)->next->content);
	last += find_pos_to_b((*stack_b), *(int *)ft_lstlast(*stack_a)->content);
	if (last < second && last < first)
	{
		if (last - 1> ft_lstsize(*stack_b) - last - 1 && last > 0)
		{
			rrr(stack_a, stack_b);
			last--;
		}
		else
			rev_rotate(stack_a, 'a');
		place_index(stack_b, last - 1, 'b');
		//push_x('b', stack_a, stack_b);
	}
	else if (second < last && second < first)
	{
		if (second - 1 < ft_lstsize(*stack_b) - second - 1 && second > 0)
		{
			rr(stack_a, stack_b);
			second--;
		}
		else
			rotate(stack_a, 'a');
		place_index(stack_b, second - 1, 'b');
		//push_x('b', stack_a, stack_b);
	}
	else
		place_index(stack_b, first, 'b');
}
