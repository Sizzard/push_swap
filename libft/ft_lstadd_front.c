/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:39:34 by facarval          #+#    #+#             */
/*   Updated: 2023/12/07 15:05:32 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*second_elem;

	second_elem = *lst;
	new->next = second_elem;
	*lst = new;
}
