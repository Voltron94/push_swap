/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:30:46 by eprieur           #+#    #+#             */
/*   Updated: 2026/01/02 20:32:58 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../push_swap.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/* Utils */

int		ft_strlen(char *str);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr, char **argv, t_list *stack_a);
int		ft_arg_len(char **av);
int		*copy_cat(t_list *lst, int size);
void	sort_int_tab(int *tab, unsigned int size);

/* linked base */

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);

#endif