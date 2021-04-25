/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:37:15 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/25 21:15:40 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute_instruction(char *instruc, t_stack **st_a, t_stack **st_b)
{
	if (ft_strncmp(instruc, "sa", 3) == 0)
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

int	ft_isalpha_lower(int c)
{
	if ((c >= 97 && c <= 122))
		return (1);
	return (0);
}

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha_lower(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	read_and_execute(t_stack **st_a, t_stack **st_b)
{
	int		i;
	char	*read;

	i = 1;
	while (i > 0)
	{
		i = get_next_line(0, &read);
		if (i == -1)
			exit_error("Error en la lectura");
		if (!check_spaces(read))
		{
			if (i != 0)
			{
				execute_instruction(read, st_a, st_b);
				printf("\033[32m%s\n\033[0m", read);
				print_stack(*st_a, 'a', read);
				print_stack(*st_b, 'b', read);
			}
		}
		else
			exit_error("Error\n");
		free(read);
	}
}
