/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:33:46 by facarval          #+#    #+#             */
/*   Updated: 2023/12/19 11:33:58 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// Renvoie 1 si pas trie 0 sinon
int	is_sorted(t_pile *stack_a)
{
	t_pile	*current;
	int		ref;

	current = stack_a;
	ref = INT_MIN;
	while (current)
	{
		if (ref > current->number)
			return (1);
		ref = current->number;
		current = current->next;
	}
	return (0);
}

// Trouve le maximum de la liste et renvoie sa position
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

// Trouve le moins couteux a push en fonction
// du chunk_size et renvoie sa position
int	pos_nearest(t_pile **liste, int chunk_size)
{
	t_pile *current;
	int res2;
	int i;
	int res;

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
		if (res2)
			return (i + 1);
	}
	return (res);
}