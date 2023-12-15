/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:14:31 by facarval          #+#    #+#             */
/*   Updated: 2023/12/15 12:12:12 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sa(t_pile **stack_a, int i)
{
	t_pile	*current;
	int		tmp;

	current = *stack_a;
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = current->number;
	current = current->next;
	(*stack_a)->number = current->number;
	current->number = tmp;
	if (i == 1)
		ft_printf("sa\n");
}

void	sb(t_pile **stack_b, int i)
{
	t_pile	*current;
	int		tmp;

	current = *stack_b;
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = current->number;
	current = current->next;
	(*stack_b)->number = current->number;
	current->number = tmp;
	if (i == 1)
		ft_printf("sb\n");
}

void	ss(t_pile **stack_a, t_pile **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_printf("ss\n");
}
