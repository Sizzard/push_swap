/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:33:46 by facarval          #+#    #+#             */
/*   Updated: 2023/12/19 13:25:27 by facarval         ###   ########.fr       */
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

int	pos_nearest2(t_pile **liste, t_pile *current, t_rank var, int chunk_size)
{
	while (var.res == 0)
	{
		if (chunk_size >= current->number)
			var.res = var.i;
		var.i++;
		current = current->next;
	}
	if (!current)
		return (var.res);
	while (current->next)
		current = current->next;
	var.i = len_list(liste);
	while (var.ref == 0)
	{
		if (chunk_size >= current->number)
			var.ref = var.i;
		var.i--;
		current = current->previous;
	}
	var.ref = len_list(liste) - var.i;
	if (var.res > var.ref && var.ref)
		return (var.i + 1);
	return (var.res);
}

// Trouve le moins couteux a push en fonction
// du chunk_size et renvoie sa position
int	pos_nearest(t_pile **liste, int chunk_size)
{
	t_pile	*current;
	t_rank	var;

	if (!*liste)
		return (0);
	else if (!(*liste)->next)
		return (1);
	var.res = 0;
	var.ref = 0;
	var.i = 1;
	current = *liste;
	return (pos_nearest2(liste, current, var, chunk_size));
}
