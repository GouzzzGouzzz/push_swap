/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:14:00 by gouz              #+#    #+#             */
/*   Updated: 2023/03/11 15:20:49 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_list *stack)
{
	int	min;
	int	index;
	int	loop_index;

	loop_index = 0;
	index = 0;
	if (!stack)
		return (0);
	min = *(int *)stack->content;
	while (stack != NULL)
	{
		if (*(int *)stack->content < min)
		{
			min = *(int *)stack->content;
			index = loop_index;
		}
		loop_index++;
		stack = stack->next;
	}
	return (index);
}

int	get_max_index(t_list *stack)
{
	int	max;
	int	index;
	int	loop_index;

	loop_index = 0;
	index = 0;
	if (!stack)
		return (0);
	max = *(int *)stack->content;
	while (stack != NULL)
	{
		if (*(int *)stack->content > max)
		{
			max = *(int *)stack->content;
			index = loop_index;
		}
		loop_index++;
		stack = stack->next;
	}
	return (index);
}

void	place_index(t_list **stack, int index, char name)
{
	if (index > ft_lstsize(*stack) - index)
	{
		index = ft_lstsize(*stack) - index;
		while (index > 0)
		{
			rev_rotate(stack, name);
			index--;
		}
	}
	else
	{
		while (index > 0)
		{
			rotate(stack, name);
			index--;
		}
	}
}

int	get_minmax_value(t_list *stack, int min)
{
	int	value;

	value = *(int *)stack->content;
	while (stack != NULL)
	{
		if (*(int *)stack->content < value && min == 1)
			value = *(int *)stack->content;
		else if (*(int *)stack->content > value && min != 1)
			value = *(int *)stack->content;
		stack = stack->next;
	}
	return (value);
}
