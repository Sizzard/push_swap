/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:28:47 by facarval          #+#    #+#             */
/*   Updated: 2024/07/08 18:03:38 by facarval         ###   ########.fr       */
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
int	find_clos_smallest(t_pile **stack_a, t_pile **stack_b)
{
	int		i;
	int		idx;
	t_pile	*tmp;

	idx = 0;
	i = INT_MAX;
	tmp = *stack_b;
	while (tmp)
	{
		if ((*stack_a)->number - tmp->number >= 0)
		{
			i = idx;
			(*stack_a)->target = tmp;
		}
		idx++;
		tmp = tmp->next;
	}
	if (i == INT_MAX)
	{
		set_max_target(stack_a, stack_b);
		return (find_max(stack_b));
	}
	return (i);
}

/*************************************************************/

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
// Set la target de root B quand A n'a pas de max
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

int	find_clos_biggest(t_pile **stack_a, t_pile **stack_b)
{
	int		i;
	int		idx;
	t_pile	*tmp;

	idx = 0;
	i = INT_MAX;
	tmp = *stack_a;
	while (tmp)
	{
		// printf("tmp->number : %d stack_b->number : %d\n", tmp->number,
		// 	(*stack_b)->number);
		printf("tmp->number : %d (*stack_b)->number : %d\n", tmp->number,
			(*stack_b)->number);
		if (tmp->number - (*stack_b)->number <= 0)
		{
			i = idx;
			(*stack_b)->target = tmp;
		}
		idx++;
		tmp = tmp->next;
	}
	if (i == INT_MAX)
	{
		printf("TEST\n");
		set_min_target(stack_a, stack_b);
		return (find_min(stack_a));
	}
	printf("i : %d\n", i);
	return (i);
}

void	do_index(t_pile **stack)
{
	t_pile	*tmp;
	int		i;
	int		len;

	len = len_list(stack);
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
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

void	sort(t_pile **stack_a, t_pile **stack_b)
{
	t_pile	*tmp;
	int		i;
	int		min_cost;
	int		min_nb;
	bool	median;
	int		max_nb;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (len_list(stack_a) != 3)
	{
		min_cost = INT_MAX;
		i = 0;
		tmp = *stack_a;
		while (tmp)
		{
			tmp->closest = find_clos_smallest(&tmp, stack_b) + i;
			i++;
			tmp = tmp->next;
		}
		do_index(stack_a);
		do_index(stack_b);
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
		while ((*stack_a)->number != min_nb)
		{
			if (median)
				rra(stack_a, 1);
			else
				ra(stack_a, 1);
		}
		min_cost = INT_MAX;
		tmp = *stack_b;
		while (tmp)
		{
			if (tmp->closest < min_cost)
			{
				min_nb = tmp->number;
				min_cost = tmp->closest;
			}
			tmp = tmp->next;
		}
		while ((*stack_a)->target != *stack_b)
		{
			if ((*stack_a)->target->under_median == true)
				rrb(stack_b, 1);
			else
				rb(stack_b, 1);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	printf("\n");
	do_index(stack_b);
	/*******************************************************/
	while (*stack_b != NULL)
	{
		print_list(*stack_a, 'a');
		print_list(*stack_b, 'b');
		min_cost = INT_MAX;
		i = 0;
		tmp = *stack_b;
		while (tmp)
		{
			tmp->closest = find_clos_biggest(stack_a, &tmp) + i;
			i++;
			tmp = tmp->next;
		}
		printf("target : %d\n", (*stack_b)->target->number);
		// tmp = *stack_b;
		// while (tmp)
		// {
		// 	printf("clos : %d\n", tmp->closest);
		// 	tmp = tmp->next;
		// }
		do_index(stack_a);
		do_index(stack_b);
		tmp = *stack_b;
		while (tmp)
		{
			// printf("tmp->closest : %d\n", tmp->closest);
			if (tmp->closest < min_cost)
			{
				max_nb = tmp->number;
				min_cost = tmp->closest;
				median = tmp->under_median;
			}
			tmp = tmp->next;
		}
		// printf("max_nb : %d , min_cost : %d, median : %d\n", max_nb,
		// min_cost, median);
		while ((*stack_b)->number != max_nb)
		{
			if (median)
				rrb(stack_b, 1);
			else
				rb(stack_b, 1);
		}
		// printf("(*stack_b)->target : %d, *stack_a : %d\n",
		// 	(*stack_b)->target->number, (*stack_a)->number);
		min_cost = INT_MAX;
		tmp = *stack_a;
		while (tmp)
		{
			if (tmp->closest < min_cost)
			{
				min_nb = tmp->number;
				min_cost = tmp->closest;
			}
			tmp = tmp->next;
		}
		printf("(*stack_b)->target : %d, *stack_a : %d\n",
			(*stack_b)->target->number, (*stack_a)->number);
		while ((*stack_b)->target != *stack_a)
		{
			// printf("(*stack_b)->target : %d\n", (*stack_b)->target->number);
			// printf("(*stack_a)->number : %d\n", (*stack_a)->number);
			if ((*stack_b)->target->under_median == true)
				rra(stack_a, 1);
			else
				ra(stack_a, 1);
		}
		pa(stack_a, stack_b);
	}
	print_list(*stack_a, 'a');
}
