/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:50:21 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/20 20:33:18 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	if (n == 0)
		return (0);
	while ((n - 1) > 0)
	{
		if (s1[i] == '\0' || s1[i] != s2[i])
			return ((unsigned char)s1[i] - s2[i]);
		i++;
		n--;
	}
	return ((unsigned char)s1[i] - s2[i]);
}


void	print_instruction(t_oper *oper)
{
	t_oper	*aux;
	int i;

	i = 1;
	aux = oper;
	while (aux->next != NULL)
	{
		printf("instruction %d: %s \n", i ,aux->instruc);
		aux = aux->next;
		i++;
	}
}

t_oper	*create_instruction(char *instruction)
{
	t_oper *new;

	new = (t_oper *)malloc(sizeof(t_oper));
	if (new == NULL)
		exit_error("Unable to allocate memory");
	new->instruc = instruction;
	new->next = NULL;
	return (new);
}

int add_instruction(t_oper **operations, char *instruction)
{
	t_oper *new;
	t_oper *aux;

	aux = *operations; 
	new = create_instruction(instruction);
	if (new == NULL)
		exit_error("Unable to allocate memory");
	if (*operations == NULL)
	{
		new->next = *operations;
		*operations = new;
	}
	else
	{
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
	}
	return (0);
}

void	read_operation(t_oper **operations)
{
	int i;
	char *read;

	i = 1;
	while (i > 0)
	{
		i = get_next_line(0, &read);
		if (i == -1)
			exit_error("Error en la lectura");
		if (add_instruction(operations, read) != 0)
			exit_error("Error al añadir nuevo elemento");
	}
}

void execute_instruction(t_oper *oper, t_stack **st_a, t_stack **st_b)
{
	t_oper *aux;

	aux = oper;

	while (aux->next != NULL)
	{
		if (oper->instruc == NULL)
				exit_error("Error\nInvalid instruction\n");
		else if (ft_strncmp(oper->instruc, "sa", 2) == 0)
			sa(st_a);
		else if (ft_strncmp(oper->instruc, "ra", 2) == 0)
			ra(st_a);
		else if (ft_strncmp(oper->instruc, "rra", 2) == 0)
			rra(st_a);
		aux = aux->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack *h_stack_a;
	t_stack *h_stack_b;
	t_oper *h_oper;

	h_stack_a = NULL;
	h_stack_b = NULL;
	h_oper = NULL;
	
	check_arg(argc, argv);
	if (argc > 2)
	{
		load_stack(&h_stack_a, argc, argv);
		print_stack(h_stack_a, 'a');
		read_operation(&h_oper);
		execute_instruction(h_oper, &h_stack_a, &h_stack_b);
		print_instruction(h_oper);
		print_stack(h_stack_a, 'a');
	}
	return (0);
}
// si no existe la instruccion debe dar error
// gcc checker.c get_next_line.c get_next_line_utils.c utils.c utils_stack.c check_arg.c operation_push.c operation_rotate.c operation_swap.c operation_reverse_rotate.c 