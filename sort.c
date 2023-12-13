/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:28:47 by facarval          #+#    #+#             */
/*   Updated: 2023/12/13 18:46:38 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// trouve le minimun de la liste et renvoie sa position
int	min_list(t_pile **liste)
{
	t_pile	*current;
	int		ref;
	int		i;
	int		res;

	res = 0;
	ref = INT_MAX;
	i = 1;
	current = *liste;
	while (current)
	{
		if (ref > current->number)
		{
			res = i;
			ref = current->number;
		}
		i++;
		current = current->next;
	}
	return (res);
}
// trouve le maximum de la liste et renvoie sa position
int	max_list(t_pile **liste)
{
	t_pile	*current;
	int		ref;
	int		i;
	int		res;

	res = 0;
	ref = INT_MIN;
	i = 1;
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

// Calcule la taille de la liste
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

// trouve le moins couteux a push en fonction du chunk_sizes
int	pos_nearest(t_pile **liste, int chunk_size)
{
	t_pile	*current;
	int		res2;
	int		i;
	int		res;

	if (!*liste)
		return (0);
	else if (!(*liste)->next)
		return (1);
	res = 0;
	res2 = 0;
	i = 1;
	current = *liste;
	while (res == 0)
	{
		if (chunk_size >= current->number)
			res = i;
		i++;
		current = current->next;
	}
	if (!current)
		return (res);
	while (current->next)
		current = current->next;
	i = len_list(liste);
	while (res2 == 0)
	{
		if (chunk_size >= current->number)
			res2 = i;
		i--;
		current = current->previous;
	}
	res2 = len_list(liste) - i;
	if (res > res2)
	{
		if (res2 )
		return (i + 1);
	}
	return (res);
}

// pretrie dans la stack b puis trie dnas la stack a
void	sort(t_pile **stack_a, t_pile **stack_b)
{
	float	compteur;
	int		min_pos;
	int		len;
	int		pos;
	int		cost;
	float	chunk_size;
	int chunk_number;
	int		max_pos;
	float		total_len;

	max_pos = 0;
	compteur = 1;
	min_pos = min_list(stack_a) - 1;
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
		else if (len / 2 <= max_pos)
		{
			while (compteur++ != len - max_pos)
				rrb(stack_b, 1);
		}
		pa(stack_a, stack_b);
		if (len_list(stack_b) == 0)
			break ;
	}
}
