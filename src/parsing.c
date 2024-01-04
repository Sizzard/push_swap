/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:07:59 by facarval          #+#    #+#             */
/*   Updated: 2024/01/04 11:05:16 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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

int	ft_parsing3(char **argv, t_pile **liste, char **nb)
{
	int	j;

	j = 0;
	while (argv[1][j] == ' ')
		j++;
	if (argv[1][j] == 0)
		return (1);
	nb = ft_split(&argv[1][j], ' ');
	if (!nb)
		return (1);
	if (ft_parsing2(nb, liste) == 1)
		return (free_split(nb), free_list(liste), 1);
	return (free_split(nb), 0);
}

int	ft_parsing(int argc, char **argv, t_pile **liste)
{
	char		**nb;
	int			i;
	int			j;
	long long	nombre;

	j = 0;
	i = 1;
	nb = NULL;
	if (argc == 1)
		exit(1);
	if (argc == 2 && ft_parsing3(argv, liste, nb) == 1)
		return (1);
	else if (argc != 2)
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
