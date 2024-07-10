/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:28:47 by facarval          #+#    #+#             */
/*   Updated: 2024/07/10 11:07:29 by facarval         ###   ########.fr       */
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

void	sort_three(t_pile **tmp)
{
	if (len_list(tmp) != 3)
		return ;
	else if ((*tmp)->number > (*tmp)->next->number
		&& (*tmp)->number < (*tmp)->next->next->number)
		sa(tmp, 1);
	else if ((*tmp)->number < (*tmp)->next->number
		&& (*tmp)->number > (*tmp)->next->next->number)
		rra(tmp, 1);
	else if ((*tmp)->number > (*tmp)->next->number
		&& (*tmp)->next->number > (*tmp)->next->next->number)
	{
		sa(tmp, 1);
		rra(tmp, 1);
	}
	else if ((*tmp)->number > (*tmp)->next->number
		&& (*tmp)->next->number < (*tmp)->next->next->number)
		ra(tmp, 1);
	else if ((*tmp)->number < (*tmp)->next->number
		&& (*tmp)->number < (*tmp)->next->next->number)
	{
		rra(tmp, 1);
		sa(tmp, 1);
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
