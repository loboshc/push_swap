/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:50:21 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/22 00:57:13 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

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
	if (ft_strncmp(instruc, "sa", 2) == 0)
		sa(st_a, 1);
	else if (ft_strncmp(instruc, "sb", 3) == 0)
		sb(st_b, 1);
	else if (ft_strncmp(instruc, "ss", 3) == 0)
		ss(st_a, st_b, 1);
	else if (ft_strncmp(instruc, "pa", 3) == 0)
		pa(st_a, st_b, 1);
	else if (ft_strncmp(instruc, "pb", 3) == 0)
		pb(st_b, st_a, 1);
	else if (ft_strncmp(instruc, "ra", 3) == 0)
		ra(st_a, 1);
	else if (ft_strncmp(instruc, "rb", 3) == 0)
		rb(st_b, 1);
	else if (ft_strncmp(instruc, "rr", 3) == 0)
		rr(st_a, st_b, 1);
	else if (ft_strncmp(instruc, "rra", 4) == 0)
		rra(st_a, 1);
	else if (ft_strncmp(instruc, "rrb", 4) == 0)
		rrb(st_b, 1);
	else if (ft_strncmp(instruc, "rrr", 4) == 0)
		rrr(st_a, st_b, 1);
	else
		exit_error("Error\n");
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
		{
			if (i != 0)
				execute_instruction(read, st_a, st_b);
		}
		else
			exit_error("Error\n");
	}
}

int	main(int argc, char **argv)
{
	t_stack	*h_stack_a;
	t_stack	*h_stack_b;

	h_stack_a = NULL;
	h_stack_b = NULL;
	
	check_arg(argc, argv);
	if (argc > 2)
	{
		load_stack(&h_stack_a, argc, argv);
		read_and_execute(&h_stack_a, &h_stack_b);
		if (is_sorted(h_stack_a) == 0 && stack_len(h_stack_b) == 0)
			printf("OK\n");
		else
			printf("KO\n");
	}
	return (0);
}
// gcc -o checker checker.c get_next_line.c get_next_line_utils.c utils.c utils_stack.c check_arg.c operation_push.c operation_rotate.c operation_swap.c operation_reverse_rotate.c 