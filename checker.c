/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:50:21 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/19 18:57:21 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_operation()
{
	
}

int	main(int argc, char **argv)
{
	t_stack *h_stack_a;
	t_stack *h_stack_b;

	h_stack_a = NULL;
	h_stack_b = NULL;
	if (argc > 2)
	{
		check_arg(argc, argv);
		load_stack(&h_stack_a, argc, argv);
		
	}
	return (0);
}
