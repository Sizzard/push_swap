/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:07:59 by facarval          #+#    #+#             */
/*   Updated: 2023/12/13 14:42:46 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
					return (1);
				comp = comp->next;
			}
			current = current->next;
			if (current)
				comp = current->next;
		}
	}
	return (0);
}

char	*res_split(char **str)
{
	static int	i;
	int			j;
	char		*line;

	j = 0;
	i++;
	line = ft_calloc(11, 1);
	if (!str[i - 1])
		return (NULL);
	while (str[i - 1][j])
	{
		line[j] = str[i - 1][j];
		j++;
	}
	return (line);
}

int	ft_parsing2(char **nbs, t_pile **liste)
{
	char	*res;

	while (1)
	{
		res = res_split(nbs);
		if (!res)
			return (0);
		if (ft_check_error(res) == 1)
		{
			free(res);
			return (1);
		}
		create_list(liste, ft_atoi(res));
		free(res);
	}
	return (0);
}

int	ft_parsing(int argc, char **argv, t_pile **liste)
{
	char	**nb;
	int		i;

	i = 1;
	if (argc == 1)
		exit(1);
	nb = ft_split(argv[1], ' ');
	if (argc == 2)
	{
		if (ft_parsing2(nb, liste) == 1)
			return (1);
	}
	else
	{
		while (i < argc)
		{
			if (ft_check_error(argv[i]) == 1)
				return (1);
			create_list(liste, ft_atoi(argv[i]));
			i++;
		}
	}
	free (nb);
	return (0);
}
