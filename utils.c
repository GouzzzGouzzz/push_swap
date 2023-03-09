/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:38:39 by gouz              #+#    #+#             */
/*   Updated: 2023/03/06 17:43:53 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	msg_error(char *str)
{
	int	i;

	i = -1;
	write(1, "Error : ", 8);
	while (str[++i])
		write(1, &str[i], 1);
	return (-1);
}

char	*add_arg(char *curr_arg, int max_len, int index, char *add_arg)
{
	if (index == 1)
		curr_arg = free_strjoin(curr_arg, add_arg, 0);
	else
		curr_arg = free_strjoin(curr_arg, add_arg, 1);
	if (index + 1 != max_len)
		curr_arg = free_strjoin(curr_arg, " ", 1);
	return (curr_arg);
}

static int	is_valid(char *numb)
{
	int	i;
	int	flag;

	flag = 0;
	i = -1;
	while (numb[++i])
	{
		if (numb[i] == '-' || numb[i] == '+')
		{
			flag++;
			if (numb[i + 1] != '+' && numb[i + 1] != '-')
				i++;
			else
				break ;
		}
		if (flag > 1)
			return (-1);
		if (ft_isalnum(numb[i]) != 4)
			return (-1);
	}
	return (1);
}

char	*join_arg(int argc, char **argv, char *full_arg)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (is_valid(argv[i]) == -1)
		{
			if (full_arg[0] != '\0')
				free(full_arg);
			return (NULL);
		}
		full_arg = add_arg(full_arg, argc, i, argv[i]);
	}
	return (full_arg);
}
