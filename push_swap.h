/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:33:43 by eprieur           #+#    #+#             */
/*   Updated: 2026/01/02 18:46:49 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

void				ft_sa(t_list **lst);
void				ft_sb(t_list **lst);
void				ft_ss(t_list **stack_a, t_list **stack_b);
void				ft_pa(t_list **stack_a, t_list **stack_b);
void				ft_pb(t_list **stack_a, t_list **stack_b);
void				ft_ra(t_list **stack_a);
void				ft_rb(t_list **stack_b);
void				ft_rr(t_list **stack_a, t_list **stack_b);
void				ft_rra(t_list **stack_a);
void				ft_rrb(t_list **stack_b);
void				ft_rrr(t_list **stack_a, t_list **stack_b);
void				swap(t_list **stack_a, t_list **stack_b, char choice);
void				push(t_list **stack_a, t_list **stack_b, char choice);
void				rotate(t_list **stack_a, t_list **stack_b, char choice);
void				reverse_rotate(t_list **stack_a, t_list **stack_b,
						char choice);
t_list				*ft_unlink_h(t_list **stack);
t_list				*ft_unlink_tail(t_list **stack);
void				ft_push_h(t_list **stack, t_list *node);
void				ft_push_tail(t_list **stack, t_list *node);
void				indexation(t_list **stack_a, t_list **stack_b);
void				radix(t_list **stack_a, t_list **stack_b);
void 				spe_mov(t_list **stack_a, t_list **stack_b, int size);
void				three_case(t_list **stack_a, t_list **stack_b);
void				ft_memory_heaven(t_list **stack_a, t_list **stack_b);
void				free_tab(char **tab, int size);
void				fill_stack_a(int size, char **argv, t_list **stack_a);
void				argv_check(char **s, int size);

#endif