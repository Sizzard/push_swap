/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:43:42 by facarval          #+#    #+#             */
/*   Updated: 2023/12/13 10:07:12 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Met B sur A
void	pa(t_pile **stack_a, t_pile **stack_b)
{
	t_pile	*tmp;

	if (!*stack_b)
		return ;
	tmp = *stack_b;
	if (!*stack_a)
	{
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->previous = NULL;
		tmp->next = NULL;
		tmp->previous = NULL;
		*stack_a = tmp;
	}
	else
	{
		if ((*stack_b)->next)
			(*stack_b)->previous = NULL;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		(*stack_a)->previous = tmp;
		*stack_a = tmp;
	}
	ft_printf("pa\n");
}

// Met A sur B
void	pb(t_pile **stack_a, t_pile **stack_b)
{
	t_pile	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_a;
	if (!*stack_b)
	{
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->previous = NULL;
		tmp->next = NULL;
		tmp->previous = NULL;
		*stack_b = tmp;
	}
	else
	{
		if ((*stack_a)->next)
			(*stack_a)->previous = NULL;
		*stack_a = (*stack_a)->next;
		tmp->next = *stack_b;
		(*stack_b)->previous = tmp;
		*stack_b = tmp;
	}
	ft_printf("pb\n");
}
