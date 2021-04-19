/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:13:12 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/19 16:35:45 by dlobos-m         ###   ########.fr       */
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

	// print list

	int j = 0;
	printf("Lista ordenada: \n ");
	while (j < i)
	{
		printf("%d, ", list_aux[j]);
		j++;
	}

	free(list_aux);
	return (0);
}

void	long_sort(char **argv, int argc, t_stack **st_a , t_stack **st_b)
{
	if (find_pos(st_a, argc, argv) == 1)
		exit_error("Error");
	printf("Hola");
}