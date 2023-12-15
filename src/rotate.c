/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:51:55 by facarval          #+#    #+#             */
/*   Updated: 2023/12/14 12:05:25 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Met premier de A a la fin de A
void	ra(t_pile **stack_a, int i)
{
	t_pile	*tmp;
	t_pile	*head;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	head = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->previous = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	head->previous = tmp;
	head->next = NULL;
	if (i == 1)
		ft_printf("ra\n");
}

void	rb(t_pile **stack_b, int i)
{
	t_pile	*tmp;
	t_pile	*head;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	head = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->previous = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	head->previous = tmp;
	head->next = NULL;
	if (i == 1)
		ft_printf("rb\n");
}

void	rr(t_pile **stack_a, t_pile **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_printf("rr\n");
}
