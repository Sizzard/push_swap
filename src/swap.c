/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:14:31 by facarval          #+#    #+#             */
/*   Updated: 2024/07/08 15:03:29 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sa(t_pile **root, int i)
{
	t_pile	*a;
	t_pile	*b;
	t_pile	*c;

	if (!(*root) || !((*root)->next))
		return ;
	a = *root;
	b = (*root)->next;
	c = b->next;
	b->next = a;
	a->next = c;
	*root = b;
	if (i == 1)
		ft_printf("sa\n");
}

void	sb(t_pile **root, int i)
{
	t_pile	*a;
	t_pile	*b;
	t_pile	*c;

	if (!(*root) || !((*root)->next))
		return ;
	a = *root;
	b = (*root)->next;
	c = b->next;
	b->next = a;
	a->next = c;
	*root = b;
	if (i == 1)
		ft_printf("sb\n");
}

void	ss(t_pile **stack_a, t_pile **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_printf("ss\n");
}
