/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_of.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:12:15 by gouz              #+#    #+#             */
/*   Updated: 2023/02/11 15:56:04 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_of(const char *nptr, int *flag)
{
	long int	converted;
	int			sign;
	int			i;

	converted = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		converted = converted * 10 + (nptr[i] - '0');
		i++;
		if ((converted > 2147483647 && sign == 1)
			|| (converted > 2147483648 && sign == -1))
			flag[0] = 1;
	}
	return (converted * sign);
}
