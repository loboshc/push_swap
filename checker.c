/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:50:21 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/20 21:46:55 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isalpha_lower(int c)
{
	if ((c >= 97 && c <= 122))
		return (1);
	return (0);
}

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

void execute_instruction(char *instruc, t_stack **st_a, t_stack **st_b)
{

	if (instruc == NULL)
		exit_error("Error\nInvalid instruction\n");
	else if (ft_strncmp(instruc, "sa", 2) == 0)
		sa(st_a);
	else if (ft_strncmp(instruc, "ra", 2) == 0)
		ra(st_a);
	else if (ft_strncmp(instruc, "rra", 2) == 0)
		rra(st_a);
}

int	check_spaces(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (ft_isalpha_lower(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	read_and_execute(t_stack **st_a, t_stack **st_b)
{
	int i;
	char *read;

	i = 1;
	while (i > 0)
	{
		i = get_next_line(0, &read);
		if (i == -1)
			exit_error("Error en la lectura");
		if (!check_spaces(read))
			execute_instruction(read, st_a, st_b);
		else
			exit_error("Error\n");
		if (is_sorted(*st_a) == 0 && stack_len(*st_b) == 0)
			break ;
	}
}

int	main(int argc, char **argv)
{
	t_stack *h_stack_a;
	t_stack *h_stack_b;

	h_stack_a = NULL;
	h_stack_b = NULL;
	
	check_arg(argc, argv);
	if (argc > 2)
	{
		load_stack(&h_stack_a, argc, argv);
		print_stack(h_stack_a, 'a');
		read_and_execute(&h_stack_a, &h_stack_b);
		print_stack(h_stack_a, 'a');
	}
	return (0);
}
// si no existe la instruccion debe dar error
// gcc checker.c get_next_line.c get_next_line_utils.c utils.c utils_stack.c check_arg.c operation_push.c operation_rotate.c operation_swap.c operation_reverse_rotate.c 