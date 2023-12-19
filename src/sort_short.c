/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:47:05 by facarval          #+#    #+#             */
/*   Updated: 2023/12/19 13:47:26 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Suite de sort three
void	sort_three_one(t_pile **stack_a, t_pile **stack_b)
{
	pb(stack_a, stack_b);
	sa(stack_a, 1);
	pa(stack_a, stack_b);
}

// Trie une liste de taille 3
void	sort_three(t_pile **stack_a, t_pile **stack_b)
{
	t_pile	*current;

	current = *stack_a;
	if (current->number == 1)
		sort_three_one(stack_a, stack_b);
	else if (current->number == 2)
	{
		current = current->next;
		if (current->number > current->next->number)
			rra(stack_a, 1);
		else
			sa(stack_a, 1);
	}
	else
	{
		current = current->next;
		if (current->number == 1)
			ra(stack_a, 1);
		else
		{
			ra(stack_a, 1);
			sa(stack_a, 1);
		}
	}
}

// Trie une liste de taille 3 avec la config d'une lsite de 5
void	sort_three5(t_pile **stack_a, t_pile **stack_b)
{
	t_pile	*current;

	current = *stack_a;
	if (current->number == 3)
		sort_three_one(stack_a, stack_b);
	else if (current->number == 4)
	{
		current = current->next;
		if (current->number > current->next->number)
			rra(stack_a, 1);
		else
			sa(stack_a, 1);
	}
	else
	{
		current = current->next;
		if (current->number == 3)
			ra(stack_a, 1);
		else
		{
			ra(stack_a, 1);
			sa(stack_a, 1);
		}
	}
}

// Trie une liste de taille 5

void	sort_five(t_pile **stack_a, t_pile **stack_b)
{
	while ((*stack_a)->number != 1 && (*stack_a)->number != 2)
		ra(stack_a, 1);
	pb(stack_a, stack_b);
	while ((*stack_a)->number != 1 && (*stack_a)->number != 2)
		ra(stack_a, 1);
	pb(stack_a, stack_b);
	if (is_sorted(*stack_a) == 1)
		sort_three5(stack_a, stack_b);
	sort_big(stack_a, stack_b);
}
