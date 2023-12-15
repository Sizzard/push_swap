/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:54:06 by facarval          #+#    #+#             */
/*   Updated: 2023/12/14 15:40:29 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Met dernier de A sur A
void	rra(t_pile **stack_a, int i)
{
	t_pile	*tmp;
	t_pile	*end;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	while (tmp->next)
	{
		end = tmp;
		tmp = tmp->next;
	}
	end->next = NULL;
	(*stack_a)->previous = tmp;
	tmp->next = *stack_a;
	*stack_a = tmp;
	if (i == 1)
		ft_printf("rra\n");
}

void	rrb(t_pile **stack_b, int i)
{
	t_pile	*tmp;
	t_pile	*end;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	while (tmp->next)
	{
		end = tmp;
		tmp = tmp->next;
	}
	end->next = NULL;
	(*stack_b)->previous = tmp;
	tmp->next = *stack_b;
	*stack_b = tmp;
	if (i == 1)
		ft_printf("rrb\n");
}

void	rrr(t_pile **stack_a, t_pile **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_printf("rrr\n");
}
