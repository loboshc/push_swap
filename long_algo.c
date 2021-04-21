/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:13:12 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/21 17:59:34 by dlobos-m         ###   ########.fr       */
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
/*
	int j = 0;
	printf("Lista ordenada: \n ");
	while (j < i)
	{
		printf("%d, ", list_aux[j]);
		j++;
	}
	*/
	free(list_aux);
	return (0);
}

int	search_next_item(t_stack *st_a,int len_a,  int len_chunk)
{
	t_stack *aux;
	int pos;

	aux = st_a;
	pos = 0;
	while (aux != NULL)
	{
		if (aux->pos >= (len_a - len_chunk)) // si encuentro un elemento del chunck
		{
			if (pos >= (len_a / 2)) 
				return (1);
		}
		pos++;
		aux = aux->next;
	}
	// si retorna 1 esta mas cerca del final del stack
	// si retorna 0 estas mas cerca del principio del stack
	return (0);
}

int	search_next_greater(t_stack *st_b, int max)
{
	t_stack *aux;
	int pos;
	int len_b;

	aux = st_b;
	pos = 0;
	len_b = stack_len(st_b);
	while (aux != NULL)
	{
		if (aux->pos == max)
			if (pos > (len_b / 2))
				return (1); 
		aux = aux->next;
		pos++;
	}
	return (0);
}

void	create_chunk(t_stack **st_a, t_stack **st_b)
{
	int len_a;
	int len_b;

	len_a = stack_len(*st_a) - 1;
	len_b = stack_len(*st_b);
	while (stack_len(*st_b) - len_b <= (len_a / 5))
	{
		if ((*st_a)->pos >= (len_a - (len_a / 5)))
			pb(st_b, st_a, 0);
		else
		{
			if (search_next_item(*st_a, len_a, (len_a / 5)) == 0)
			{
				while ((*st_a)->pos < (len_a - (len_a / 5)))
					ra(st_a, 0);
			}
			else
				while ((*st_a)->pos < (len_a - (len_a / 5)))
					rra(st_a, 0);
		}
	}
}

void return_greater_to_a(t_stack **st_a, t_stack **st_b)
{
	int max;

	while (stack_len(*st_b) > 0)
	{
		max = get_max_pos(st_b);
		if ((*st_b)->pos == max)
			pa(st_a, st_b, 0);
		else
		{
			if (search_next_greater(*st_b, max) == 1)
			{
				while((*st_b)->pos != max)
					rrb(st_b, 0);
			}
			else
			{
				while((*st_b)->pos != max)
					rb(st_b, 0);
			}
		}
	}
}

void	long_sort(char **argv, int argc, t_stack **st_a , t_stack **st_b)
{
	if (find_pos(st_a, argc, argv) == 1) // asigno la posicion ordenada
		exit_error("Error\n");
	while (stack_len(*st_a) >= 5)
		create_chunk(st_a, st_b);
	while((*st_a)->pos != 3)
		ra(st_a, 0);
	pb(st_b, st_a, 0);
	sort_3(st_a);
	return_greater_to_a(st_a, st_b);
	while (is_sorted(*st_a) == 1)
		rra(st_a, 0);
}