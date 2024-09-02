/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:33:25 by facarval          #+#    #+#             */
/*   Updated: 2024/07/10 16:07:05 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Trouve le minimum de la liste et renvoie sa position
int	find_min(t_pile **liste)
{
	t_pile	*current;
	int		ref;
	int		i;
	int		res;

	res = 0;
	ref = INT_MAX;
	i = 0;
	current = *liste;
	while (current)
	{
		if (ref > current->number)
		{
			res = i;
			ref = current->number;
		}
		i++;
		current = current->next;
	}
	return (res);
}

void	set_min_target(t_pile **stack_a, t_pile **stack_b)
{
	int		i;
	t_pile	*tmp;

	tmp = *stack_a;
	i = find_min(stack_a);
	while (i != 0)
	{
		tmp = tmp->next;
		i--;
	}
	(*stack_b)->target = tmp;
}

void	find_clos_biggest(t_pile **stack_a, t_pile **stack_b)
{
	int		last_max;
	t_pile	*tmp;

	last_max = INT_MAX;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->number > (*stack_b)->number && tmp->number < last_max)
		{
			last_max = tmp->number;
			(*stack_b)->target = tmp;
		}
		tmp = tmp->next;
	}
	if (last_max == INT_MAX)
	{
		set_min_target(stack_a, stack_b);
	}
}

/************************************************************************/

int	calculate_rr2(t_pile **stack_a, t_pile **stack_b, t_pile *tmp)
{
	int	pos;
	int	pos2;

	pos = get_pos(*stack_b, tmp->number);
	pos2 = get_pos(*stack_a, tmp->target->number);
	if (pos > pos2)
		return (pos);
	return (pos2);
}

int	calculate_rrr2(t_pile **stack_a, t_pile **stack_b, t_pile *tmp)
{
	int	pos;
	int	pos2;

	pos = len_list(stack_b) - get_pos(*stack_b, tmp->number) + 1;
	pos2 = len_list(stack_a) - get_pos(*stack_a, tmp->target->number) + 1;
	if (pos > pos2)
		return (pos);
	return (pos2);
}

int	calculate_ra2(t_pile **stack_a, t_pile **stack_b, t_pile *tmp)
{
	int	pos;
	int	pos2;

	pos = get_pos(*stack_b, tmp->number);
	pos2 = len_list(stack_a) - get_pos(*stack_a, tmp->target->number) + 1;
	return (pos + pos2);
}

int	calculate_rb2(t_pile **stack_a, t_pile **stack_b, t_pile *tmp)
{
	int	pos;
	int	pos2;

	pos = len_list(stack_b) - get_pos(*stack_b, tmp->number) + 1;
	pos2 = get_pos(*stack_a, tmp->target->number);
	return (pos + pos2);
}

void	find_op_rr2(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op,
		t_pile *tmp)
{
	min_op->tmp = calculate_rr2(stack_a, stack_b, tmp);
	if (min_op->tmp < min_op->cost)
	{
		min_op->cost = min_op->tmp;
		min_op->flag_op = RR;
		min_op->target_a = get_node(stack_a, get_pos(*stack_a,
					tmp->target->number));
		min_op->target_b = get_node(stack_b, get_pos(*stack_b, tmp->number));
	}
}

void	find_op_rrr2(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op,
		t_pile *tmp)
{
	min_op->tmp = calculate_rrr2(stack_a, stack_b, tmp);
	if (min_op->tmp < min_op->cost)
	{
		min_op->cost = min_op->tmp;
		min_op->flag_op = RRR;
		min_op->target_a = get_node(stack_a, get_pos(*stack_a,
					tmp->target->number));
		min_op->target_b = get_node(stack_b, get_pos(*stack_b, tmp->number));
	}
}

void	find_op_ra2(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op,
		t_pile *tmp)
{
	min_op->tmp = calculate_ra2(stack_a, stack_b, tmp);
	if (min_op->tmp < min_op->cost)
	{
		min_op->cost = min_op->tmp;
		min_op->flag_op = RA;
		min_op->target_a = get_node(stack_a, get_pos(*stack_a,
					tmp->target->number));
		min_op->target_b = get_node(stack_b, get_pos(*stack_b, tmp->number));
	}
}

void	find_op_rb2(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op,
		t_pile *tmp)
{
	min_op->tmp = calculate_rb2(stack_a, stack_b, tmp);
	if (min_op->tmp < min_op->cost)
	{
		min_op->cost = min_op->tmp;
		min_op->flag_op = RB;
		min_op->target_a = get_node(stack_a, get_pos(*stack_a,
					tmp->target->number));
		min_op->target_b = get_node(stack_b, get_pos(*stack_b, tmp->number));
	}
}

void	find_min_op2(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op)
{
	t_pile	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		find_op_rr2(stack_a, stack_b, min_op, tmp);
		find_op_rrr2(stack_a, stack_b, min_op, tmp);
		find_op_ra2(stack_a, stack_b, min_op, tmp);
		find_op_rb2(stack_a, stack_b, min_op, tmp);
		tmp = tmp->next;
	}
}

void	part2(t_pile **stack_a, t_pile **stack_b)
{
	t_cost_op	cost_op;
	t_pile		*tmp;

	while (*stack_b)
	{
		cost_op.cost = INT_MAX;
		cost_op.tmp = INT_MAX;
		cost_op.flag_op = 0;
		cost_op.target_a = NULL;
		cost_op.target_b = NULL;
		tmp = *stack_b;
		while (tmp)
		{
			find_clos_biggest(stack_a, &tmp);
			tmp = tmp->next;
		}
		find_min_op2(stack_a, stack_b, &cost_op);
		do_op(stack_a, stack_b, &cost_op);
		pa(stack_a, stack_b);
	}
	// if (find_max(stack_a) < len_list(stack_a) / 2)
	// {
	// 	while (is_sorted(*stack_a))
	// 		rra(stack_a, 1);
	// }
	// else
	// {
	// 	while (is_sorted(*stack_a))
	// 		ra(stack_a, 1);
	// }
}
