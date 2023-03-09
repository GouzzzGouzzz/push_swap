/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:45:01 by gouz              #+#    #+#             */
/*   Updated: 2023/02/27 23:04:26 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	already_sorted(t_list *stack)
{
	int	*cont;
	int	*prev_cont;

	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		prev_cont = stack->content;
		stack = stack->next;
		cont = stack->content;
		if (prev_cont[0] >= cont[0])
			return (1);
	}
	return (-1);
}

static int	is_twice_in_arr(int elt, int *tab, int index, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (tab[i] == elt && i != index)
			return (1);
	return (-1);
}

int	check_double(t_list *stack)
{
	int	*temp_double;
	int	j;
	int	len;

	len = ft_lstsize(stack);
	if (len == 0)
		return (-1);
	j = 0;
	temp_double = malloc(sizeof(int) * len);
	if (!temp_double)
		return (-1);
	while (stack->next != NULL)
	{
		temp_double[j] = *((int *)stack->content);
		j++;
		stack = stack->next;
	}
	temp_double[j] = *((int *)stack->content);
	while (j-- > 0)
		if (is_twice_in_arr(temp_double[j], temp_double, j, len) == 1)
			break ;
	free(temp_double);
	if (j >= 0)
		return (-1);
	return (1);
}

int	check_str(char *str)
{
	if (str[0] == '-')
	{
		if (!ft_isdigit(str[1]))
			return (-1);
	}
	if (str[0] != '-')
	{
		if (str[0] == '+' && !ft_isdigit(str[1]))
			return (-1);
	}
	return (1);
}
