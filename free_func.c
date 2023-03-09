/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 06:44:30 by gouz              #+#    #+#             */
/*   Updated: 2023/02/13 03:52:02 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

char	*free_strjoin(char *s1, char *s2, int to_free)
{
	int		i;
	char	*str;
	int		temp;

	if (!s1)
		return (NULL);
	str = malloc((ft_strlen(s1) + 1 + ft_strlen(s2)) * sizeof(char));
	if (!(str))
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	temp = i;
	i = -1;
	while (s2[++i])
		str[temp + i] = s2[i];
	str[temp + i] = '\0';
	if (to_free == 1 || to_free == 3)
		free(s1);
	if (to_free == 2 || to_free == 3)
		free(s2);
	return (str);
}
