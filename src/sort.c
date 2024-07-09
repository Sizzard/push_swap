/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:28:47 by facarval          #+#    #+#             */
/*   Updated: 2024/07/09 15:56:48 by facarval         ###   ########.fr       */
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

t_pile	*get_node(t_pile **stack, int pos)
{
	t_pile	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp && pos != i)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

int	get_pos(t_pile *stack, int nb)
{
	int		res;
	t_pile	*tmp;

	res = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->number == nb)
			break ;
		tmp = tmp->next;
		res++;
	}
	return (res);
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
	while ((*stack_b) != min_op->target_b)
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
	t_pile		*tmp;
	t_cost_op	cost_op;
	int			i;
	int			len;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	len = len_list(stack_a);
	while (len > 3)
	{
		cost_op.cost = INT_MAX;
		cost_op.flag_op = 0;
		cost_op.target_a = NULL;
		cost_op.target_b = NULL;
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
		// print_lists(*stack_a, *stack_b);
		find_min_op(stack_a, stack_b, &cost_op);
		do_op(stack_a, stack_b, &cost_op);
		pb(stack_a, stack_b);
		len--;
	}
	sort_three(stack_a);
	printf("\n");
	do_median(stack_b);
	/*******************************************************/
	// print_lists(*stack_a, *stack_b);
}
