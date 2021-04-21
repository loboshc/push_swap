/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 01:03:23 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/22 01:04:02 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_list(int *list_aux, int size)
{
	int i;
	int j;
	int tmp;
	
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (list_aux[j + 1] < list_aux[j])
			{
				tmp = list_aux[j + 1];
				list_aux[j + 1] = list_aux[j];
				list_aux[j] = tmp;
			}
			j++;
		}
		i++;
	}	
	return (0);
}

int assign_pos(t_stack **st_a, int *list_aux, int size)
{
	t_stack *aux;
	int i;

	aux = *st_a;
	while (aux != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (list_aux[i] == aux->num)
				aux->pos = i;
			i++;
		}
		aux = aux->next;
	}
	return (0);
}

int	find_pos(t_stack **st_a, int argc, char **argv)
{
	int *list_aux;
	t_stack *aux;
	int i;
	
	i = 0;
	aux = *st_a;
	list_aux = (int*)malloc(sizeof(int) * argc - 1);
	argv++;
	while(aux != NULL)
	{
		list_aux[i] = aux->num;
		aux =  aux->next;
		i++;
	}
	if (sort_list(list_aux, argc - 1) != 0)
		return (1);
	if (assign_pos(st_a, list_aux, argc - 1) != 0)
		return (1);
	free(list_aux);
	return (0);
}
