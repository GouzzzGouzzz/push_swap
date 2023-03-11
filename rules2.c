/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:41:40 by nmorandi          #+#    #+#             */
/*   Updated: 2023/03/11 15:22:40 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap((*stack_a), 'a');
	swap((*stack_b), 'b');
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate((*stack_a), 'a');
	rotate((*stack_b), 'b');
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate((*stack_a), 'a');
	rev_rotate((*stack_b), 'b');
}
