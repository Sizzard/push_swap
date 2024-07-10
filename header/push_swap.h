/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:44:57 by facarval          #+#    #+#             */
/*   Updated: 2024/07/10 11:39:06 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libftprintf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pile
{
	int				number;
	struct s_pile	*target;
	struct s_pile	*next;
	struct s_pile	*previous;
}					t_pile;

typedef struct s_cost_op
{
	int				flag_op;
	int				cost;
	int				tmp;
	t_pile			*target_a;
	t_pile			*target_b;
}					t_cost_op;

enum				e_op
{
	RR = 0,
	RRR = 1,
	RA = 2,
	RB = 3,
};

int					ft_check_error(char *str);
char				*res_split(char **str);
int					ft_parsing(int argc, char **argv, t_pile **pile);
t_pile				*create_node(int number);
void				add_node(t_pile **head, t_pile *new);
void				create_list(t_pile **liste, int number);
int					ft_check_double(t_pile **liste);
int					len_list(t_pile **liste);
int					is_sorted(t_pile *stack_a);
int					ft_atoi_check(const char *nptr, long long *nombre);
int					ft_check_error(char *str);
int					ft_check_double(t_pile **liste);

/*						Instructions :					*/
/*						Takes 1 to print					*/

void				sa(t_pile **stack_a, int i);
void				sb(t_pile **stack_b, int i);
void				ss(t_pile **stack_a, t_pile **stack_b);
void				pa(t_pile **stack_a, t_pile **stack_b);
void				pb(t_pile **stack_a, t_pile **stack_b);
void				ra(t_pile **stack_a, int i);
void				rb(t_pile **stack_b, int i);
void				rr(t_pile **stack_a, t_pile **stack_b);
void				rra(t_pile **stack_a, int i);
void				rrb(t_pile **stack_b, int i);
void				rrr(t_pile **stack_a, t_pile **stack_b);

/*						Operations 						*/

void				do_op(t_pile **stack_a, t_pile **stack_b,
						t_cost_op *min_op);
void				do_op_rb(t_pile **stack_a, t_pile **stack_b,
						t_cost_op *min_op);
void				do_op_ra(t_pile **stack_a, t_pile **stack_b,
						t_cost_op *min_op);
void				do_op_rrr(t_pile **stack_a, t_pile **stack_b,
						t_cost_op *min_op);
void				do_op_rr(t_pile **stack_a, t_pile **stack_b,
						t_cost_op *min_op);
void				find_min_op(t_pile **stack_a, t_pile **stack_b,
						t_cost_op *min_op);

/*						Calculations					*/

int					calculate_rb(t_pile **stack_a, t_pile **stack_b,
						t_pile *tmp);
int					calculate_ra(t_pile **stack_a, t_pile **stack_b,
						t_pile *tmp);
int					calculate_rrr(t_pile **stack_a, t_pile **stack_b,
						t_pile *tmp);
int					calculate_rr(t_pile **stack_a, t_pile **stack_b,
						t_pile *tmp);
void				find_min_op(t_pile **stack_a, t_pile **stack_b,
						t_cost_op *min_op);

/*						Setting Target					*/

void				find_clos_smallest(t_pile **stack_a, t_pile **stack_b);
void				set_max_target(t_pile **stack_a, t_pile **stack_b);
int					find_max(t_pile **liste);

void				sort(t_pile **stack_a, t_pile **stack_b);
void				part2(t_pile **stack_a, t_pile **stack_b);

int					len_list(t_pile **liste);
int					get_pos(t_pile *stack, int nb);
t_pile				*get_node(t_pile **stack, int pos);

void				sort_three(t_pile **root_a);

void				print_list(t_pile *head, char list);
void				print_lists(t_pile *stack_a, t_pile *stack_b);

void				free_list(t_pile **stack_a);
#endif