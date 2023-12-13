/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:05:57 by facarval          #+#    #+#             */
/*   Updated: 2023/12/06 14:51:13 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*

int	main(void)
{
	int				t;
	unsigned char	tab[] = "abpd";
	unsigned char	temoin[] = "abcd";
	unsigned char	tab2[] = "abpd";
	unsigned char	temoin2[] = "abcd";

	t = 4;
	printf("%d\n", ft_memcmp(tab, temoin, t));
	printf("%d", memcmp(tab2, temoin2, t));
}

*/