/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_less_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:33:18 by facarval          #+#    #+#             */
/*   Updated: 2024/07/10 11:37:20 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	find_op_rr(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op,
		t_pile *tmp)
{
	min_op->tmp = calculate_rr(stack_a, stack_b, tmp);
	if (min_op->tmp < min_op->cost)
	{
		min_op->cost = min_op->tmp;
		min_op->flag_op = RR;
		min_op->target_a = get_node(stack_a, get_pos(*stack_a, tmp->number));
		min_op->target_b = get_node(stack_b, get_pos(*stack_b,
					tmp->target->number));
	}
}

void	find_op_rrr(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op,
		t_pile *tmp)
{
	min_op->tmp = calculate_rrr(stack_a, stack_b, tmp);
	if (min_op->tmp < min_op->cost)
	{
		min_op->cost = min_op->tmp;
		min_op->flag_op = RRR;
		min_op->target_a = get_node(stack_a, get_pos(*stack_a, tmp->number));
		min_op->target_b = get_node(stack_b, get_pos(*stack_b,
					tmp->target->number));
	}
}

void	find_op_ra(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op,
		t_pile *tmp)
{
	min_op->tmp = calculate_ra(stack_a, stack_b, tmp);
	if (min_op->tmp < min_op->cost)
	{
		min_op->cost = min_op->tmp;
		min_op->flag_op = RA;
		min_op->target_a = get_node(stack_a, get_pos(*stack_a, tmp->number));
		min_op->target_b = get_node(stack_b, get_pos(*stack_b,
					tmp->target->number));
	}
}

void	find_op_rb(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op,
		t_pile *tmp)
{
	min_op->tmp = calculate_rb(stack_a, stack_b, tmp);
	if (min_op->tmp < min_op->cost)
	{
		min_op->cost = min_op->tmp;
		min_op->flag_op = RB;
		min_op->target_a = get_node(stack_a, get_pos(*stack_a, tmp->number));
		min_op->target_b = get_node(stack_b, get_pos(*stack_b,
					tmp->target->number));
	}
}

void	find_min_op(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op)
{
	t_pile	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		find_op_rr(stack_a, stack_b, min_op, tmp);
		find_op_rrr(stack_a, stack_b, min_op, tmp);
		find_op_ra(stack_a, stack_b, min_op, tmp);
		find_op_rb(stack_a, stack_b, min_op, tmp);
		tmp = tmp->next;
	}
}
