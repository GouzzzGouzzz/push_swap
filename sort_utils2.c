/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:56:59 by gouz              #+#    #+#             */
/*   Updated: 2023/03/11 15:14:15 by gouz             ###   ########.fr       */
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
