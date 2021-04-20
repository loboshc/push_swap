/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:28:25 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/20 21:48:45 by dlobos-m         ###   ########.fr       */
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

int	ft_number(const char *n)
{
	long int	i[3];

	i[0] = 0;
	i[2] = 0;
	i[1] = 1;
	while (n[i[0]] == 32 || (n[i[0]] >= 9 && n[i[0]] <= 13))
		i[0]++;
	if (n[i[0]] == '-' || n[i[0]] == '+')
	{
		if (n[i[0]] == '-')
			i[1] = (i[1] * (-1));
		i[0]++;
	}
	while (('9' >= n[i[0]]) && (n[i[0]] >= '0'))
	{
		i[2] = (i[2] * 10) + (n[i[0]] - '0');
		i[0]++;
		if (i[2] * i[1] > 2147483647)
			exit_error("Error\nInvalid arguments\n");
		else if (i[2] * i[1] < -2147483648)
			exit_error("Error\nInvalid arguments\n");
	}
	if (!ft_isdigit(n[i[0]]) && n[i[0]] != '\0')
		exit_error("Error\nInvalid arguments\n");
	return (i[2] * i[1]);
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
	int	tmp;
	int	j;
	t_stack	*aux;

	aux = stack;
	j = 0;
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
