/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:30:14 by facarval          #+#    #+#             */
/*   Updated: 2024/07/09 18:28:22 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Trouve le maximum de la liste et renvoie sa position
int	find_max(t_pile **liste)
{
	t_pile	*current;
	int		ref;
	int		i;
	int		res;

	res = 0;
	ref = INT_MIN;
	i = 0;
	current = *liste;
	while (current)
	{
		if (ref < current->number)
		{
			res = i;
			ref = current->number;
		}
		i++;
		current = current->next;
	}
	return (res);
}

// Set la target de root A quand B na pas de min
void	set_max_target(t_pile **stack_a, t_pile **stack_b)
{
	int		i;
	t_pile	*tmp;

	tmp = *stack_b;
	i = find_max(stack_b);
	while (i != 0)
	{
		tmp = tmp->next;
		i--;
	}
	(*stack_a)->target = tmp;
}

// Set la target de root A et renvoie la position du closest_smaller
void	find_clos_smallest(t_pile **stack_a, t_pile **stack_b)
{
	int		last_min;
	t_pile	*tmp;

	last_min = INT_MAX;
	tmp = *stack_b;
	while (tmp)
	{
		if ((*stack_a)->number - tmp->number >= 0
			&& last_min > (*stack_a)->number - tmp->number)
		{
			last_min = (*stack_a)->number - tmp->number;
			(*stack_a)->target = tmp;
		}
		tmp = tmp->next;
	}
	if (last_min == INT_MAX)
	{
		set_max_target(stack_a, stack_b);
	}
}

int	calculate_rr(t_pile **stack_a, t_pile **stack_b, t_pile *tmp)
{
	int	pos;
	int	pos2;

	pos = get_pos(*stack_a, tmp->number);
	pos2 = get_pos(*stack_b, tmp->target->number);
	if (pos > pos2)
		return (pos);
	return (pos2);
}

int	calculate_rrr(t_pile **stack_a, t_pile **stack_b, t_pile *tmp)
{
	int	pos;
	int	pos2;

	pos = len_list(stack_a) - get_pos(*stack_a, tmp->number) + 1;
	pos2 = len_list(stack_b) - get_pos(*stack_b, tmp->target->number) + 1;
	if (pos > pos2)
		return (pos);
	return (pos2);
}

int	calculate_ra(t_pile **stack_a, t_pile **stack_b, t_pile *tmp)
{
	int	pos;
	int	pos2;

	pos = get_pos(*stack_a, tmp->number);
	pos2 = len_list(stack_b) - get_pos(*stack_b, tmp->target->number) + 1;
	return (pos + pos2);
}

int	calculate_rb(t_pile **stack_a, t_pile **stack_b, t_pile *tmp)
{
	int	pos;
	int	pos2;

	pos = len_list(stack_a) - get_pos(*stack_a, tmp->number) + 1;
	pos2 = get_pos(*stack_b, tmp->target->number);
	return (pos + pos2);
}

void	find_min_op(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op)
{
	t_pile		*tmp;
	t_cost_op	cost_op;

	cost_op.cost = min_op->cost;
	cost_op.flag_op = 0;
	cost_op.target_a = NULL;
	cost_op.target_b = NULL;
	tmp = *stack_a;
	while (tmp)
	{
		cost_op.cost = calculate_rr(stack_a, stack_b, tmp);
		if (cost_op.cost < min_op->cost)
		{
			min_op->cost = cost_op.cost;
			min_op->flag_op = RR;
			min_op->target_a = get_node(stack_a, get_pos(*stack_a,
						tmp->number));
			min_op->target_b = get_node(stack_b, get_pos(*stack_b,
						tmp->target->number));
		}
		cost_op.cost = calculate_rrr(stack_a, stack_b, tmp);
		if (cost_op.cost < min_op->cost)
		{
			min_op->cost = cost_op.cost;
			min_op->flag_op = RRR;
			min_op->target_a = get_node(stack_a, get_pos(*stack_a,
						tmp->number));
			min_op->target_b = get_node(stack_b, get_pos(*stack_b,
						tmp->target->number));
		}
		cost_op.cost = calculate_ra(stack_a, stack_b, tmp);
		if (cost_op.cost < min_op->cost)
		{
			min_op->cost = cost_op.cost;
			min_op->flag_op = RA;
			min_op->target_a = get_node(stack_a, get_pos(*stack_a,
						tmp->number));
			min_op->target_b = get_node(stack_b, get_pos(*stack_b,
						tmp->target->number));
		}
		cost_op.cost = calculate_rb(stack_a, stack_b, tmp);
		if (cost_op.cost < min_op->cost)
		{
			min_op->cost = cost_op.cost;
			min_op->flag_op = RB;
			min_op->target_a = get_node(stack_a, get_pos(*stack_a,
						tmp->number));
			min_op->target_b = get_node(stack_b, get_pos(*stack_b,
						tmp->target->number));
		}
		tmp = tmp->next;
	}
}

void	do_op_rr(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op)
{
	while ((*stack_a) != min_op->target_a && (*stack_b) != min_op->target_b)
	{
		rr(stack_a, stack_b);
	}
	while ((*stack_a) != min_op->target_a)
	{
		ra(stack_a, 1);
	}
	while (*stack_b && (*stack_b) != min_op->target_b)
	{
		rb(stack_b, 1);
	}
}

void	do_op_rrr(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op)
{
	while ((*stack_a) != min_op->target_a && *stack_b != min_op->target_b)
	{
		rrr(stack_a, stack_b);
	}
	while ((*stack_a) != min_op->target_a)
	{
		rra(stack_a, 1);
	}
	while (*stack_b != min_op->target_b)
	{
		rrb(stack_b, 1);
	}
}

void	do_op_ra(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op)
{
	while (*stack_a != min_op->target_a)
	{
		ra(stack_a, 1);
	}
	while (*stack_b != min_op->target_b)
	{
		rrb(stack_b, 1);
	}
}

void	do_op_rb(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op)
{
	while (*stack_a != min_op->target_a)
	{
		rra(stack_a, 1);
	}
	while (*stack_b != min_op->target_b)
	{
		rb(stack_b, 1);
	}
}

void	do_op(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op)
{
	if (min_op->flag_op == RR)
	{
		do_op_rr(stack_a, stack_b, min_op);
	}
	else if (min_op->flag_op == RRR)
	{
		do_op_rrr(stack_a, stack_b, min_op);
	}
	else if (min_op->flag_op == RA)
	{
		do_op_ra(stack_a, stack_b, min_op);
	}
	else if (min_op->flag_op == RB)
	{
		do_op_rb(stack_a, stack_b, min_op);
	}
}

void	sort(t_pile **stack_a, t_pile **stack_b)
{
	t_pile *tmp;
	t_cost_op cost_op;
	int len;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	len = len_list(stack_a);
	while (len != 0)
	{
		cost_op.cost = INT_MAX;
		cost_op.flag_op = 0;
		cost_op.target_a = NULL;
		cost_op.target_b = NULL;
		tmp = *stack_a;
		while (tmp)
		{
			find_clos_smallest(&tmp, stack_b);
			tmp = tmp->next;
		}
		find_min_op(stack_a, stack_b, &cost_op);
		do_op(stack_a, stack_b, &cost_op);
		pb(stack_a, stack_b);
		len--;
	}
	sort_three(stack_a);
	part2(stack_a, stack_b);
}