/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:44:35 by facarval          #+#    #+#             */
/*   Updated: 2024/07/10 11:06:38 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

int	is_sorted(t_pile *stack_a)
{
	t_pile	*current;
	int		ref;

	current = stack_a;
	ref = INT_MIN;
	while (current)
	{
		if (ref > current->number)
			return (1);
		ref = current->number;
		current = current->next;
	}
	return (0);
}

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
	if (is_sorted(stack_a) == 1)
	{
		if (len_list(&stack_a) == 3)
			sort_three(&stack_a);
		// else if (len_list(&stack_a) == 5)
		// 	sort_five(&stack_a, &stack_b);
		else
			sort(&stack_a, &stack_b);
	}
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
