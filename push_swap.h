/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:37:16 by gouz              #+#    #+#             */
/*   Updated: 2023/03/12 16:10:02 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

/* Utils */
int		msg_error(char *str);
void	free_split(char **split);
int		ft_atoi_of(const char *nptr, int *flag);
char	*free_strjoin(char *s1, char *s2, int to_free);
char	*add_arg(char *curr_arg, int max_len, int index, char *add_arg);
char	*join_arg(int argc, char **argv, char *full_arg);
void	place_index(t_list **stack, int index, char name);
int		get_min_index(t_list *stack);
int		get_max_index(t_list *stack);
int		get_minmax_value(t_list *stack, int min);

/* Parsing */
int		parse(char **argv, int one_arg, t_list **list, int argc);
int		already_sorted(t_list *stack);
int		check_double(t_list *stack);
int		check_str(char *str);

/* Rules */
void	swap(t_list **stack, char c);
void	rotate(t_list **stack, char c);
void	rev_rotate(t_list **stack, char c);
void	push_x(char c, t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

void	print_list(t_list *start);

/* Sort */
int		large_sort(t_list **stack, t_list **stack_b);
void	sort_three(t_list **stack);

int		push_cmd_a(t_list **stack_a, t_list **stack_b);
int		push_cmd_b(t_list **stack_a, t_list **stack_b);
int		find_pos_to_a(t_list *stack, int nb);
int		find_pos_to_b(t_list *stack, int nb);

int		calculated_push(t_list **stack_a, t_list **stack_b);
#endif
