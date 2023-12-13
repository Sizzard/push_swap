/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:12:25 by facarval          #+#    #+#             */
/*   Updated: 2023/12/06 14:51:02 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	list = *lst;
	last = 0;
	while (list != NULL)
	{
		last = list;
		list = list->next;
	}
	last->next = new;
}
