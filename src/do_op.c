/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:32:48 by facarval          #+#    #+#             */
/*   Updated: 2024/07/10 15:20:38 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	do_op_rr(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op)
{
	while ((*stack_a) != min_op->target_a && (*stack_b) != min_op->target_b)
	{
		rr(stack_a, stack_b);
	}
	while (*stack_a && (*stack_a) != min_op->target_a)
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
	while (*stack_a && (*stack_a) != min_op->target_a)
	{
		rra(stack_a, 1);
	}
	while (*stack_b && *stack_b != min_op->target_b)
	{
		rrb(stack_b, 1);
	}
}

void	do_op_ra(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op)
{
	while (*stack_a && *stack_a != min_op->target_a)
	{
		ra(stack_a, 1);
	}
	while (*stack_b && *stack_b != min_op->target_b)
	{
		rrb(stack_b, 1);
	}
}

void	do_op_rb(t_pile **stack_a, t_pile **stack_b, t_cost_op *min_op)
{
	while (*stack_a && *stack_a != min_op->target_a)
	{
		rra(stack_a, 1);
	}
	while (*stack_b && *stack_b != min_op->target_b)
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
