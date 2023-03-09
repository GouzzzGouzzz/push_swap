/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:32:57 by gouz              #+#    #+#             */
/*   Updated: 2023/03/03 16:13:13 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	add_to_list(t_list **list, char *data, int *flag)
{
	int		*temp;
	t_list	*cell;

	temp = malloc(sizeof(int));
	if (!temp)
		return (msg_error("Memory error\n"));
	temp[0] = ft_atoi_of(data, flag);
	cell = ft_lstnew(&temp[0]);
	ft_lstadd_back(list, cell);
}

int	fill_list(t_list **list, char *arg)
{
	char	**data;
	int		i;
	int		*flag;

	flag = malloc(sizeof(int));
	if (!flag)
		return (msg_error("Memory error\n"));
	flag[0] = 0;
	i = -1;
	data = ft_split(arg, ' ');
	if (!data)
		return (msg_error("Memory error\n"));
	while (data[++i])
	{
		if (check_str(data[i]) == -1)
			flag[0] = 1;
		add_to_list(list, data[i], flag);
	}
	free_split(data);
	if (flag[0] == 1)
		i = -1;
	free(flag);
	if (i == -1)
		return (msg_error("Int Overflow / + and - without number\n"));
	return (1);
}

static int	parse_one(char *arg)
{
	int	i;
	int	nb_total;
	int	flag;

	flag = 1;
	nb_total = 0;
	i = -1;
	while (arg[++i] && flag >= 0)
	{
		while (arg[i] == ' ' && arg[i + 1])
		{
			flag = 1;
			i++;
		}
		if (ft_isalnum(arg[i]) != 4 && arg[i] != '-' && arg[i] != '+')
			flag = -1;
		if (flag > 0)
			nb_total++;
		if (flag > 0)
			flag = 0;
	}
	if (nb_total < 2 || flag < 0)
		return (msg_error("Not enough number or contains invalid symbols\n"));
	return (1);
}

int	parse(char **argv, int one_arg, t_list **list, int argc)
{
	char	*full_arg;
	int		ret;

	ret = 1;
	full_arg = "\0";
	if (one_arg)
	{
		if (parse_one(argv[1]) == 1)
			return (fill_list(list, argv[1]));
		else
			return (-1);
	}
	full_arg = join_arg(argc, argv, full_arg);
	if (!full_arg)
		return (-1);
	if (parse_one(full_arg) == 1)
		ret = fill_list(list, full_arg);
	free(full_arg);
	return (ret);
}
