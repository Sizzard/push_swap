/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:03:03 by facarval          #+#    #+#             */
/*   Updated: 2023/12/06 14:52:09 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = dest;
	s = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*

int	main(void)
{
	char	tab1[] = "";
	char	tab2[] = "";
	char	tab3[] = "";
	char	tab4[] = "";
	size_t	t;

	t = 0;
	ft_memcpy(tab2, tab1, t);
	memcpy(tab4, tab3, t);
	printf("Ma fonction : %s\n", tab2);
	printf("Vraie fonction :%s\n", tab4);
}

*/