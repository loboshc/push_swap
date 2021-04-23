/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:28:25 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/23 17:44:55 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	exit_error(char *string)
{
	printf("%s", string);
	exit(EXIT_FAILURE);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

t_stack	*last_element(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	while (aux->next != NULL)
		aux = aux->next;
	return (aux);
}

int	is_sorted(t_stack *stack)
{
	int		j;
	t_stack	*aux;

	aux = stack;
	j = 0;
	if (aux == NULL)
		return (1);
	while (aux->next != NULL)
	{
		if (aux->num < aux->next->num)
			j++;
		aux = aux->next;
	}
	if (j + 1 == stack_len(stack))
		return (0);
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_stack	*aux;

	aux = NULL;
	while (stack != NULL)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
}
