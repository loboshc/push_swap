/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:50:21 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/27 20:29:46 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_execute(t_stack **st_a, t_stack **st_b, int flag, char *read)
{
	execute_instruction(read, st_a, st_b);
	if (flag == 3 || flag == 1)
		printf("\033[32m%s\n\033[0m", read);
	if (flag == 2 || flag == 3)
	{
		if (flag != 3)
			printf("%s\n", read);
		print_stack(*st_a, 'a', read, flag);
		print_stack(*st_b, 'b', read, flag);
	}
}

void	check_flag(int argc, char **argv, int *flag)
{
	argv++;
	if (argc > 2)
	{
		if (ft_strncmp(argv[0], "-c", 3) == 0)
			*flag = 1;
		else if (ft_strncmp(argv[0], "-v", 3) == 0)
			*flag = 2;
		else if (ft_strncmp(argv[0], "-cv", 4) == 0)
			*flag = 3;
		else
			*flag = 0;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*h_stack_a;
	t_stack	*h_stack_b;
	int		flag;

	h_stack_a = NULL;
	h_stack_b = NULL;
	check_flag(argc, argv, &flag);
	check_arg(argc, argv, flag);
	if (argc > 2)
	{
		if (argc == 3 && flag > 0)
			return (0);
		load_stack(&h_stack_a, argc, argv, flag);
		read_and_execute(&h_stack_a, &h_stack_b, flag);
		if (is_sorted(h_stack_a) == 0 && stack_len(h_stack_b) == 0)
			printf("OK\n");
		else
			printf("KO\n");
	}
	free_stack(h_stack_a);
	free_stack(h_stack_b);
	return (0);
}
