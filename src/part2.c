/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:33:25 by facarval          #+#    #+#             */
/*   Updated: 2024/07/10 10:22:35 by facarval         ###   ########.fr       */
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

	last_max = INT_MIN;
	tmp = *stack_b;
	while (tmp)
	{
		if ((*stack_a)->number - tmp->number >= 0
			&& last_max > (*stack_a)->number - tmp->number)
		{
			last_max = (*stack_a)->number - tmp->number;
			(*stack_a)->target = tmp;
		}
		tmp = tmp->next;
	}
	if (last_max == INT_MIN)
	{
		set_min_target(stack_a, stack_b);
	}
}

void	part2(t_pile **stack_a, t_pile **stack_b)
{
	int	len;

	len = len_list(stack_b);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
	}
	while (is_sorted(*stack_a))
	{
		if (find_max(stack_a) > len / 2)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
	}
}
