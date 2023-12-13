/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:28:24 by facarval          #+#    #+#             */
/*   Updated: 2023/12/06 14:52:02 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = 0;
	while (lst)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}
