#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h> //exit() compris
# include <unistd.h>

/* --- Linked instruction --- */

void				ft_sa(t_list **lst);						//	switch the two first element at the top fo the stack A
void				ft_sb(t_list **lst);						//	same like sa but for the stack b
void				ft_ss(t_list **stack_a, t_list **stack_b);	//	sa + sb
void				ft_pa(t_list **stack_a, t_list **stack_b);	//	the first element of B become the first element of A
void				ft_pb(t_list **stack_a, t_list **stack_b);	//	the first element of A become the first element of B
void				ft_ra(t_list **stack_a);					//	the first element become the last
void				ft_rb(t_list **stack_b);					// 	same like rb for the stack b
void 				ft_rr(t_list **stack_a, t_list **stack_b);	//	ra + rb
void    			ft_rra(t_list **stack_a);					//	the last element become the first
void				ft_rrb(t_list **stack_b);					//	same like rra for the stack n
void				ft_rrr(t_list **stack_a, t_list **stack_b);	//	rra + rrb

/* --- Instruction choice --- */

void				swap(t_list **stack_a, t_list **stack_b, char choice);
void				push(t_list **stack_a, t_list **stack_b, char choice);
void				rotate(t_list **stack_a, t_list **stack_b, char choice);
void				reverse_rotate(t_list **stack_a, t_list **stack_b, char choice);

/* --- Linked utils --- */

t_list 				*ft_unlink_h(t_list **stack);
t_list				*ft_unlink_tail(t_list **stack);
void 				ft_push_h(t_list **stack, t_list *node);
void				ft_push_tail(t_list **stack, t_list *node);

/* --- Algo --- */

void				indexation(t_list **stack_a, t_list **stack_b);
void				print_index(t_list *lst); //	A supprimer !
void 				radix(t_list **stack_a, t_list **stack_b);
void 				two_case(t_list **stack_a, t_list **stack_b);
void 				three_case(t_list **stack_a, t_list **stack_b);

/* --- Free --- */

void 				ft_memory_heaven(t_list **stack_a, t_list **stack_b);
void 				free_tab(char **tab, int size);

#endif