/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:28:47 by facarval          #+#    #+#             */
/*   Updated: 2024/07/09 13:34:17 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	print_lists(t_pile *stack_a, t_pile *stack_b)
{
	t_pile	*tmp_a;
	t_pile	*tmp_b;

	tmp_a = stack_a;
	tmp_b = stack_b;
	ft_printf("         Liste 'a'         |         Liste 'b'         \n\n");
	while (tmp_a && tmp_b)
	{
		ft_printf("         %d                 |         %d         \n",
			tmp_a->number, tmp_b->number);
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
	}
	while (tmp_a)
	{
		ft_printf("         %d                 |                    \n",
			tmp_a->number);
		tmp_a = tmp_a->next;
	}
	while (tmp_b)
	{
		ft_printf("                           |         %d         \n",
			tmp_b->number);
		tmp_b = tmp_b->next;
	}
}

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
int	find_clos_smallest(t_pile **stack_a, t_pile **stack_b)
{
	int		i;
	int		idx;
	int		last_min;
	t_pile	*tmp;

	last_min = INT_MAX;
	idx = 0;
	i = INT_MAX;
	tmp = *stack_b;
	while (tmp)
	{
		// printf("res : %d\n", (*stack_a)->number - tmp->number);
		if ((*stack_a)->number - tmp->number >= 0
			&& last_min > (*stack_a)->number - tmp->number)
		{
			last_min = (*stack_a)->number - tmp->number;
			i = idx;
			(*stack_a)->target = tmp;
		}
		idx++;
		tmp = tmp->next;
	}
	// printf("last_min : %d\n", last_min);
	if (i == INT_MAX)
	{
		set_max_target(stack_a, stack_b);
		return (find_max(stack_b));
	}
	return (i);
}

void	do_median(t_pile **stack)
{
	t_pile	*tmp;
	int		i;
	int		len;

	len = len_list(stack);
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		i++;
		if (i > len / 2)
		{
			tmp->under_median = true;
		}
		else
			tmp->under_median = false;
		tmp = tmp->next;
	}
}

void	sort_three(t_pile **root_a)
{
	t_pile	*tmp;

	tmp = *root_a;
	if (len_list(&tmp) != 3)
		return ;
	else if (tmp->number > tmp->next->number
		&& tmp->number < tmp->next->next->number)
	{
		sa(root_a, 1);
	}
	else if (tmp->number < tmp->next->number
		&& tmp->number > tmp->next->next->number)
	{
		rra(root_a, 1);
	}
	else if (tmp->number > tmp->next->number
		&& tmp->next->number > tmp->next->next->number)
	{
		sa(root_a, 1);
		rra(root_a, 1);
	}
	else if (tmp->number > tmp->next->number
		&& tmp->next->number < tmp->next->next->number)
	{
		ra(root_a, 1);
	}
	else if (tmp->number < tmp->next->number
		&& tmp->number < tmp->next->next->number)
	{
		rra(root_a, 1);
		sa(root_a, 1);
	}
}

int	len_list(t_pile **liste)
{
	t_pile	*current;
	int		i;

	i = 0;
	if (!*liste)
		return (0);
	current = *liste;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_pile	*get_node(t_pile **stack, int nb)
{
	t_pile	*tmp;

	tmp = *stack;
	while (tmp && tmp->number)
	{
		if (tmp->number == nb)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	sort(t_pile **stack_a, t_pile **stack_b)
{
	t_pile	*tmp;
	t_pile	*target_a;
	int		i;
	int		min_cost;
	int		min_nb;
	int		len;
	bool	median;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	len = len_list(stack_a);
	while (len > 3)
	{
		min_cost = INT_MAX;
		do_median(stack_a);
		do_median(stack_b);
		i = 0;
		tmp = *stack_a;
		while (tmp)
		{
			tmp->closest = find_clos_smallest(&tmp, stack_b) + i;
			if (tmp->under_median == false)
				i++;
			else
				i--;
			tmp = tmp->next;
		}
		tmp = *stack_a;
		while (tmp)
		{
			if (tmp->closest < min_cost)
			{
				min_nb = tmp->number;
				min_cost = tmp->closest;
				median = tmp->under_median;
			}
			tmp = tmp->next;
		}
		target_a = get_node(stack_a, min_nb);
		while ((*stack_a) != target_a)
		{
			if (target_a->target != *stack_b)
			{
				if (!median && target_a->target->under_median == false)
					rr(stack_a, stack_b);
				else
					rrr(stack_a, stack_b);
			}
			else if (!median)
				ra(stack_a, 1);
			else
				rra(stack_a, 1);
		}
		while ((*stack_a)->target != *stack_b)
		{
			if ((*stack_a)->target->under_median == false)
				rb(stack_b, 1);
			else
				rrb(stack_b, 1);
		}
		pb(stack_a, stack_b);
		len--;
	}
	sort_three(stack_a);
	printf("\n");
	do_median(stack_b);
	/*******************************************************/
	// print_lists(*stack_a, *stack_b);
}
