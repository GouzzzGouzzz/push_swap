/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:39:05 by gouz              #+#    #+#             */
/*   Updated: 2023/03/11 22:13:36 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_list(t_list *start)
{
	t_list	*start_cpy;
	int		*elem;

	start_cpy = start;
	while (start_cpy)
	{
		elem = start_cpy->content;
		printf(" %d", *elem);
		start_cpy = start_cpy->next;
	}
	printf("<- list \n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc == 1)
		return (-1);
	if (argc == 2)
	{
		if (parse(argv, 1, &stack_a, argc) == -1)
		{
			ft_lstclear(&stack_a, &free);
			return (-1);
		}
	}
	if (argc >= 3)
	{
		if (parse(argv, 0, &stack_a, argc) == -1)
		{
			ft_lstclear(&stack_a, &free);
			return (-1);
		}
	}
	if (already_sorted(stack_a) == -1)
	{
		ft_lstclear(&stack_a, &free);
		return (msg_error("Stack is already sorted\n"));
	}
	if (check_double(stack_a) == -1)
	{
		ft_lstclear(&stack_a, &free);
		return (msg_error("Stack contains at least one duplicate\n"));
	}
	if (ft_lstsize(stack_a) == 3)
		sort_three(&stack_a);
	else
		large_sort(&stack_a, &stack_b);
	//print_list(stack_a);
	ft_lstclear(&stack_b, &free);
	ft_lstclear(&stack_a, &free);
	return (0);
}
