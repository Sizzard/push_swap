/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:44:57 by facarval          #+#    #+#             */
/*   Updated: 2023/12/13 14:44:30 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libftprintf.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pile
{
	int				number;
	struct s_pile	*next;
	struct s_pile	*previous;
}					t_pile;

int					ft_check_error(char *str);
char				*res_split(char **str);
int					ft_parsing(int argc, char **argv, t_pile **pile);
t_pile				*create_node(int number);
void				add_node(t_pile **head, t_pile *new);
void				create_list(t_pile **liste, int number);
int					ft_check_double(t_pile **liste);
int					len_list(t_pile **liste);
int					min_list(t_pile **liste);
int					max_list(t_pile **liste);

/*						Instructions :					*/
/*					1 pour afficher le printf 			*/

void				sa(t_pile *stack_a, int i);
void				sb(t_pile *stack_b, int i);
void				ss(t_pile *stack_a, t_pile *stack_b);
void				pa(t_pile **stack_a, t_pile **stack_b);
void				pb(t_pile **stack_a, t_pile **stack_b);
void				ra(t_pile **stack_a, int i);
void				rb(t_pile **stack_b, int i);
void				rr(t_pile **stack_a, t_pile **stack_b);
void				rra(t_pile **stack_a, int i);
void				rrb(t_pile **stack_b, int i);
void				rrr(t_pile **stack_a, t_pile **stack_b);

void				sort(t_pile **stack_a, t_pile **stack_b);
int					pos_nearest(t_pile **liste, int chunk);

void				free_list(t_pile **stack_a);

#endif