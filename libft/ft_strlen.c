/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:41:26 by facarval          #+#    #+#             */
/*   Updated: 2023/12/06 14:52:23 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*

#include <string.h>

int	main(void)
{
	const char	str[6] = "4";
	size_t		j;

	j = 0;
	j = ft_strlen(str);
	printf("%zu", j);
	printf("\n%zu", strlen(str));
	return (0);
}

*/