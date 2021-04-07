/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:28:38 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/07 22:13:50 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arg(int argc, char *argv[])
{
	int	i;
	int	tmp;
	int	j;

	i = -1;
	argv++;
	while (++i < argc - 1)
	{
		if (*argv[i] == '-' && (argv[i][1] == '0' || argv[i][1] == '\0'))
			exit_error("Error\nInvalid arguments\n");
		tmp = ft_number(argv[i]);
		j = i;
		while (argc > --j && j >= 0)
		{
			if (tmp == ft_number(argv[j]))
				exit_error("Error\nRepeated number\n");
		}
	}
}

int	main(int argc, char *argv[])
{
	t_stack *h_stack_a;
	t_stack *h_stack_b;

	h_stack_a = NULL;
	h_stack_b = NULL;
	check_arg(argc, argv);

	int i = argc - 1;
	argv++;
	while (i-- > 0)
	{
		add_element(&h_stack_a, ft_number(argv[i]));
	}
	//print_stack(h_stack_a, 'a');
	
	return (0);
}