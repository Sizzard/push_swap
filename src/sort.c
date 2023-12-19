/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:28:47 by facarval          #+#    #+#             */
/*   Updated: 2023/12/19 13:48:54 by facarval         ###   ########.fr       */
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

void	sort2(t_pile **stack_a, t_pile **stack_b, t_sort sort, int *compteur)
{
	while (*compteur <= sort.chunk_size)
	{
		sort.pos = pos_nearest(stack_a, sort.chunk_size);
		if (sort.pos < sort.len / 2)
		{
			while (sort.pos - 1)
			{
				ra(stack_a, 1);
				sort.pos--;
			}
			pb(stack_a, stack_b);
		}
		else
		{
			sort.cost = sort.len + 1 - sort.pos;
			while (sort.cost)
			{
				rra(stack_a, 1);
				sort.cost--;
			}
			pb(stack_a, stack_b);
		}
		sort.len--;
		(*compteur)++;
	}
}

// Push en Chunk dans la B
void	sort(t_pile **stack_a, t_pile **stack_b)
{
	float	total_len;
	int		chunk_number;
	int		compteur;
	t_sort	sort;

	compteur = 1;
	sort.cost = 0;
	sort.len = 0;
	sort.pos = 0;
	total_len = len_list(stack_a);
	if (total_len > 400)
		chunk_number = 12;
	else
		chunk_number = 6;
	sort.chunk_size = total_len / chunk_number;
	while (compteur < total_len)
	{
		sort.len = len_list(stack_a);
		sort2(stack_a, stack_b, sort, &compteur);
		sort.chunk_size += total_len / chunk_number;
	}
	sort_big(stack_a, stack_b);
}
