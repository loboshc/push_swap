/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:17:51 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/22 01:06:34 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_element(int num)
{
	t_stack		*new_element;

	new_element = (t_stack *)malloc(sizeof(t_stack));
	if (new_element == NULL)
		exit_error("Unable to allocate memory");
	new_element->num = num;
	new_element->pos = 0;
	new_element->next = NULL;
	return (new_element);
}

int	add_element_stack(t_stack **stack, int num) // returns 0 if the element has been assigned to the list. 
{
	t_stack	*new;

	new = create_element(num);
	if (new == NULL)
		exit_error("Unable to allocate memory");
	else
	{
		new->next = *stack;
		*stack = new;
		return (0);
	}
	return (1);
}

void	print_stack(t_stack *stack, char letter)
{
	t_stack	*aux;

	aux = stack;
	printf("stack_%c", letter);
	while (aux != NULL)
	{
		printf(" %d", aux->num);
		aux = aux->next;
	}
	printf("\n");
}

int	stack_len(t_stack *stack)
{
	int		len;
	t_stack	*aux;

	aux = stack;
	len = 0;
	while (aux != NULL)
	{
		aux = aux->next;
		len++;
	}
	return (len);
}

void	load_stack(t_stack **stack, int argc, char **argv)
{
	int	i;

	i = argc - 1;
	argv++;
	while (i-- > 0)
		add_element_stack(stack, ft_number(argv[i]));
}
