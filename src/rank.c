/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:39:27 by facarval          #+#    #+#             */
/*   Updated: 2023/12/14 13:59:16 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

// assigne des ranks a la liste chainee et renvoie 1 si malloc echoue
// et 0 si tout s'est bien passe
int	assign_rank(t_pile **stack_a)
{
	int		*tab;
	int		i;
	int		len;
	t_pile	*current;
	int		rank;
	int		res;
	int		ref;

	rank = 1;
	current = *stack_a;
	i = 0;
	len = len_list(stack_a);
	tab = malloc(len * sizeof(int));
	if (!tab)
		return (1);
	while (i < len)
	{
		tab[i] = -1;
		i++;
	}
	while (len--)
	{
		i = 0;
		res = 0;
		ref = INT_MAX;
		current = *stack_a;
		while (current)
		{
			if (tab[i] == -1)
			{
				if (ref > current->number)
				{
					res = i;
					ref = current->number;
				}
			}
			i++;
			current = current->next;
		}
		tab[res] = rank;
		rank++;
	}
	current = *stack_a;
	i = 0;
	while (current)
	{
		current->number = tab[i];
		current = current->next;
		i++;
	}
	free(tab);
	return (0);
}
