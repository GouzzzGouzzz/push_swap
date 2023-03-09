/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:56:46 by gouz              #+#    #+#             */
/*   Updated: 2023/03/02 22:51:27 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char c)
{
	int	*temp;
	int	*temp2;

	if (!(*stack)->next)
		return ;
	temp = malloc(sizeof(int));
	temp2 = malloc(sizeof(int));
	temp[0] = *(int *)(*stack)->content;
	temp2[0] = *(int *)(*stack)->next->content;
	free((*stack)->content);
	free((*stack)->next->content);
	(*stack)->content = temp2;
	(*stack)->next->content = temp;
	if (c == 'b')
		write(1, "sb\n", 3);
	else
		write(1, "sa\n", 3);
}

void	rotate(t_list **stack, char c)
{
	t_list	*new_last;
	t_list	*last_temp;
	t_list	*new_first;

	new_first = (*stack)->next;
	last_temp = ft_lstlast((*stack));
	new_last = (*stack);
	new_last->next = NULL;
	(*stack) = new_first;
	last_temp->next = new_last;
	if (c == 'b')
		write(1, "rb\n", 3);
	else
		write(1, "ra\n", 3);
}

void	rev_rotate(t_list **stack, char c)
{
	int		i;
	t_list	*first;
	t_list	*new_first;

	i = ft_lstsize((*stack));
	new_first = ft_lstlast((*stack));
	first = (*stack);
	while (--i > 1)
		(*stack) = (*stack)->next;
	(*stack)->next = NULL;
	new_first->next = first;
	(*stack) = new_first;
	if (c == 'b')
		write(1, "rrb\n", 4);
	else
		write(1, "rra\n", 4);
}

void	push_x(char c, t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;
	t_list	*cpy;

	if (c == 'b' && (*stack_a) != NULL)
	{
		ptr = ft_lstnew((*stack_a)->content);
		ft_lstadd_front(stack_b, ptr);
		cpy = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		write(1, "pb\n", 3);
	}
	else if ((*stack_b) != NULL)
	{
		ptr = ft_lstnew((*stack_b)->content);
		ft_lstadd_front(stack_a, ptr);
		cpy = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		write(1, "pa\n", 3);
	}
	if (cpy)
		free(cpy);
}
