/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:35:46 by facarval          #+#    #+#             */
/*   Updated: 2024/07/10 10:35:57 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
