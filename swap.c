/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:14:31 by facarval          #+#    #+#             */
/*   Updated: 2023/12/13 10:07:06 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_pile *stack_a, int i)
{
	t_pile	*current;
	t_pile	*tmp;

	current = stack_a;
	tmp = (t_pile *)malloc(sizeof(t_pile));
	tmp->number = stack_a->number;
	current = current->next;
	stack_a->number = current->number;
	current->number = tmp->number;
	if (i == 1)
		ft_printf("sa\n");
	free(tmp);
}

void	sb(t_pile *stack_b, int i)
{
	t_pile	*current;
	t_pile	*tmp;

	current = stack_b;
	tmp = (t_pile *)malloc(sizeof(t_pile));
	tmp->number = stack_b->number;
	current = current->next;
	stack_b->number = current->number;
	current->number = tmp->number;
	if (i == 1)
		ft_printf("sb\n");
	free(tmp);
}

void	ss(t_pile *stack_a, t_pile *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_printf("ss\n");
}
