/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:28:47 by facarval          #+#    #+#             */
/*   Updated: 2023/12/19 11:33:43 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Push tout dans A dans le bon ordre
void	sort_big(t_pile **stack_a, t_pile **stack_b)
{
	int	max_pos;
	int	compteur;
	int	len;

	while (1)
	{
		compteur = 0;
		max_pos = max_list(stack_b) - 1;
		len = len_list(stack_b);
		if (len / 2 >= max_pos)
		{
			while (compteur++ != max_pos)
				rb(stack_b, 1);
		}
		else if (len / 2 < max_pos)
		{
			while (compteur++ != len - max_pos)
				rrb(stack_b, 1);
		}
		pa(stack_a, stack_b);
		if (len_list(stack_b) == 0)
			break ;
	}
}

// Push en Chunk dans la B
void	sort(t_pile **stack_a, t_pile **stack_b)
{
	float	compteur;
	float	chunk_size;
	int		chunk_number;
	float	total_len;
	int		len;
	int		pos;
	int		cost;

	compteur = 1;
	total_len = len_list(stack_a);
	if (total_len > 400)
		chunk_number = 12;
	else
		chunk_number = 6;
	chunk_size = total_len / chunk_number;
	while (compteur < total_len)
	{
		len = len_list(stack_a);
		while (compteur <= chunk_size)
		{
			pos = pos_nearest(stack_a, chunk_size);
			if (pos < len / 2)
			{
				while (pos - 1)
				{
					ra(stack_a, 1);
					pos--;
				}
				pb(stack_a, stack_b);
			}
			else
			{
				cost = len + 1 - pos;
				while (cost)
				{
					rra(stack_a, 1);
					cost--;
				}
				pb(stack_a, stack_b);
			}
			len--;
			compteur++;
		}
		chunk_size += total_len / chunk_number;
	}
	sort_big(stack_a, stack_b);
}

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
void	sort_three2(t_pile **stack_a, t_pile **stack_b)
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
		sort_three2(stack_a, stack_b);
	sort_big(stack_a, stack_b);
}
