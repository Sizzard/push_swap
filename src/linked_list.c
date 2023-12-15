/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:29:04 by facarval          #+#    #+#             */
/*   Updated: 2023/12/14 12:04:38 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_pile	*create_node(int number)
{
	t_pile		*new;

	new = (t_pile *)malloc(sizeof(t_pile));
	if (!new)
		return (NULL);
	new->number = number;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

void	add_node(t_pile **head, t_pile *new)
{
	t_pile	*current;

	if (*head == NULL)
		*head = new;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		new->previous = current;
	}
}

void	create_list(t_pile **liste, int number)
{
	add_node(liste, create_node(number));
}

void	free_list(t_pile **stack_a)
{
	t_pile	*tmp;

	if (!*stack_a)
		return ;
	while (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
}
