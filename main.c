/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:44:35 by facarval          #+#    #+#             */
/*   Updated: 2023/12/13 14:39:55 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_pile *head, char list)
{
	t_pile	*current;

	if (!head)
		printf("Rien dans la liste %c\n", list);
	else
	{
		printf("Liste : %c\n", list);
		current = head;
		while (current != NULL)
		{
			printf("%d\n", current->number);
			current = current->next;
		}
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_pile	*stack_a;
	t_pile	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ft_parsing(argc, argv, &stack_a) == 1 || ft_check_double(&stack_a) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	sort(&stack_a, &stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
