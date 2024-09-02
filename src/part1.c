/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:30:14 by facarval          #+#    #+#             */
/*   Updated: 2024/07/10 14:33:04 by facarval         ###   ########.fr       */
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

void	sort(t_pile **stack_a, t_pile **stack_b)
{
	t_pile		*tmp;
	t_cost_op	cost_op;
	int			len;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	len = len_list(stack_a);
	while (len > 3)
	{
		cost_op.cost = INT_MAX;
		cost_op.tmp = INT_MAX;
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
