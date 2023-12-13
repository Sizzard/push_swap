/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:02:28 by facarval          #+#    #+#             */
/*   Updated: 2023/12/06 14:50:54 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_isalnum(int c)
{
	if (((c >= '0' && c <= '9')) || (c >= 'A' && c <= 'Z') || (c >= 'a'
			&& c <= 'z'))
	{
		return (1);
	}
	return (0);
}

/*

#include <ctype.h>

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d", ft_isalnum(*argv[1]));
	printf("\n%d", isalnum(*argv[1]));
}

*/