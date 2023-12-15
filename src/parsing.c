/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:07:59 by facarval          #+#    #+#             */
/*   Updated: 2023/12/15 15:49:23 by facarval         ###   ########.fr       */
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

char	*res_split(char **str)
{
	static int	i;
	int			j;
	char		*line;

	j = 0;
	if (!str[i])
		return (NULL);
	line = ft_calloc(ft_strlen(str[i]) + 1, 1);
	if (!line)
		return (NULL);
	while (str[i][j])
	{
		line[j] = str[i][j];
		j++;
	}
	i++;
	return (line);
}

int	ft_parsing2(char **nbs, t_pile **liste)
{
	char		*res;
	long long	nombre;

	while (1)
	{
		nombre = 0;
		res = res_split(nbs);
		if (!res)
			return (0);
		if (ft_check_error(res) == 1)
			return (free(res), 1);
		if (ft_atoi_check(res, &nombre) == 1)
			return (free(res), 1);
		create_list(liste, nombre);
		free(res);
	}
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0)
	{
		free(str[i - 1]);
		i--;
	}
	free(str);
}

int	ft_parsing(int argc, char **argv, t_pile **liste)
{
	char		**nb;
	int			i;
	long long	nombre;
	int			j;

	j = 0;
	i = 1;
	if (argc == 1)
		exit(1);
	if (argc == 2)
	{
		while (argv[1][j] == ' ')
			j++;
		if (argv[1][j] == 0)
			return (1);
		nb = ft_split(&argv[1][j], ' ');
		if (!**nb)
			return (1);
		if (ft_parsing2(nb, liste) == 1)
			return (free_split(nb), free_list(liste), 1);
		free_split(nb);
	}
	else
	{
		while (i < argc)
		{
			nombre = 0;
			if (ft_check_error(argv[i]) == 1 || ft_atoi_check(argv[i],
					&nombre) == 1)
				return (free_list(liste), 1);
			create_list(liste, nombre);
			i++;
		}
	}
	return (0);
}
