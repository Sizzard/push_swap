/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:39:27 by facarval          #+#    #+#             */
/*   Updated: 2023/12/19 10:50:46 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	assign_rank2(t_pile **stack_a, int *tab, int len)
{
	t_rank	indice;

	indice.rank = 1;
	while (len--)
	{
		indice.i = 0;
		indice.res = 0;
		indice.ref = INT_MAX;
		indice.current = *stack_a;
		while (indice.current)
		{
			if (tab[indice.i] == -1)
			{
				if (indice.ref > indice.current->number)
				{
					indice.res = indice.i;
					indice.ref = indice.current->number;
				}
			}
			indice.i++;
			indice.current = indice.current->next;
		}
		tab[indice.res] = indice.rank;
		indice.rank++;
	}
}

// assigne des ranks a la liste chainee et renvoie 1 si malloc echoue
// et 0 si tout s'est bien passe
int	assign_rank(t_pile **stack_a)
{
	int		*tab;
	int		i;
	int		len;
	t_pile	*current;

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
	assign_rank2(stack_a, tab, len);
	current = *stack_a;
	i = 0;
	while (current)
	{
		current->number = tab[i];
		current = current->next;
		i++;
	}
	return (free(tab), 0);
}
