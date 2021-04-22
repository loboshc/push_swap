/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:50:21 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/22 23:14:23 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
