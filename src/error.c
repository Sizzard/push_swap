/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:53:14 by facarval          #+#    #+#             */
/*   Updated: 2023/12/19 10:54:00 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_atoi_check(const char *nptr, long long *nombre)
{
	int	i;
	int	min;

	i = 0;
	min = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		min = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		*nombre = *nombre * 10 + (nptr[i] - 48);
		if (*nombre * min < INT_MIN || *nombre * min > INT_MAX)
			return (1);
		i++;
	}
	*nombre *= min;
	return (0);
}

int	ft_check_error(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_double(t_pile **liste)
{
	t_pile	*current;
	t_pile	*comp;

	if (!*liste)
		return (1);
	else
	{
		current = *liste;
		comp = (*liste)->next;
		while (current)
		{
			while (comp)
			{
				if (current->number == comp->number)
					return (free_list(liste), 1);
				comp = comp->next;
			}
			current = current->next;
			if (current)
				comp = current->next;
		}
	}
	return (0);
}
