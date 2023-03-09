/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:54:37 by nmorandi          #+#    #+#             */
/*   Updated: 2023/03/05 19:14:13 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_list **stack, t_list **stack_b)
{
	int	index;
	int	size;
	int	flag;

	flag = 0;
	size = ft_lstsize((*stack));
	index = 0;
	while (size > 2)
	{
		index = get_min_index((*stack));
		place_index(stack, index, size);
		if (already_sorted((*stack)) == -1)
			break ;
		push_x('b', stack, stack_b);
		size--;
	}
	if (size == 2)
		if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
			swap(stack, 'a');
	while ((*stack_b) != NULL)
		push_x('a', stack, stack_b);
	ft_lstclear(stack_b, &free);
	ft_lstclear(stack, &free);
}
