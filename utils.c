/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:28:25 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/21 21:04:06 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		tmp;
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
		if (j + 1 == stack_len(stack)) // retorna 0 si esta ordenado
			return (0);
		aux = aux->next;
	}
	return (1); // si no esta ordenado retorna 1
}

int		ft_isalpha_lower(int c)
{
	if ((c >= 97 && c <= 122))
		return (1);
	return (0);
}
