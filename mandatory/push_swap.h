/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:12:15 by mfortuna          #+#    #+#             */
/*   Updated: 2024/04/10 12:50:43 by mfortuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./mylibft/mylibft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack
{
	int					data;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*prev;
}				t_stack;

char	**ft_nsplit(const char *s);
char	**ft_freearr(char	**arr, size_t word);
size_t	ft_countmywords(const char *s);
void	ft_createstack(int argc, char **argv, t_stack **a);
int		errorcheck(char **arr, size_t count);
void	ft_fillstack(char **arr, t_stack **a, int count);
t_stack	*stack_createnode(int value);
void	stack_addlast(t_stack **head, int value);
void	stack_deletelast(t_stack **head);
void	stack_bomb(t_stack **head);
int		stack_count(t_stack **head);
void	stack_order(t_stack **head);
int		ft_isitsorted(t_stack **a);
void	ft_sort(t_stack **a);
void	stack_push(t_stack **src, t_stack **dst, char *s);
void	stack_preswap(t_stack **a, t_stack **b, char *s);
void	stack_prerotate(t_stack **a, t_stack **b, char *s);
void	stack_prerevrotate(t_stack **a, t_stack **b, char *s);
t_stack	*ft_whoishigher(t_stack **head);
t_stack	*ft_whoislower(t_stack **head);
void	ft_justthree(t_stack **head, t_stack **b);
void	ft_letzsort(t_stack **a, t_stack **b);
void	a_aftermove(t_stack **src, t_stack **dst);
void	b_aftermove(t_stack **src, t_stack **dst);
void	stack_currentindex(t_stack **head);
void	a_target(t_stack **src, t_stack **dst);
void	b_target(t_stack **src, t_stack **dst);
void	stack_pushprice(t_stack **src, t_stack **dst);
t_stack	*stack_cheapest(t_stack **head);
void	a_target_top(t_stack **src, t_stack **dst);
void	a_cheap_top(t_stack **src, t_stack **dst);
void	b_target_top(t_stack **src, t_stack **dst);
void	b_cheap_top(t_stack **src, t_stack **dst);

#endif
