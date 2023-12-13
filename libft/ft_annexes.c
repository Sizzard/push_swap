/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:31:01 by facarval          #+#    #+#             */
/*   Updated: 2023/11/22 10:07:22 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd_compteur(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putunbr_fd(unsigned int n, int fd, int *compteur)
{
	if (n > 9)
		ft_putunbr_fd(n / 10, fd, compteur);
	ft_putchar_fd(n % 10 + '0', fd);
	(*compteur)++;
	return (*compteur);
}

int	ft_putnbr_fd_compteur(int n, int fd, int *compteur)
{
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n > 9)
		ft_putnbr_fd_compteur(n / 10, fd, compteur);
	ft_putchar_fd(n % 10 + '0', fd);
	(*compteur)++;
	return (*compteur);
}

int	ft_putnbrbase(unsigned long nbr, int *compteur)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
		ft_putnbrbase(nbr / 16, compteur);
	ft_putchar_fd(base[nbr % 16], 1);
	(*compteur)++;
	return (*compteur);
}

int	ft_putnbrbasemaj(unsigned int nbr, int *compteur)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr >= 16)
		ft_putnbrbasemaj(nbr / 16, compteur);
	ft_putchar_fd(base[nbr % 16], 1);
	(*compteur)++;
	return (*compteur);
}
