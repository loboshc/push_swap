/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:37:14 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/22 13:27:28 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	ft_number(const char *n)
{
	long int	i[3];

	i[0] = 0;
	i[2] = 0;
	i[1] = 1;
	while (n[i[0]] == 32 || (n[i[0]] >= 9 && n[i[0]] <= 13))
		i[0]++;
	if (n[i[0]] == '-' || n[i[0]] == '+')
	{
		if (n[i[0]] == '-')
			i[1] = (i[1] * (-1));
		i[0]++;
	}
	while (('9' >= n[i[0]]) && (n[i[0]] >= '0'))
	{
		i[2] = (i[2] * 10) + (n[i[0]] - '0');
		i[0]++;
		if (i[2] * i[1] > 2147483647)
			exit_error("Error\n");
		else if (i[2] * i[1] < -2147483648)
			exit_error("Error\n");
	}
	if (!ft_isdigit(n[i[0]]) && n[i[0]] != '\0')
		exit_error("Error\n");
	return (i[2] * i[1]);
}

void	check_arg(int argc, char **argv)
{
	int	i;
	int	tmp;
	int	j;

	i = -1;
	argv++;
	while (++i < argc - 1)
	{
		if ((*argv[i] == '-' || *argv[i] == '+') && argv[i][1] == '\0')
			exit_error("Error\n");
		tmp = ft_number(argv[i]);
		j = i;
		while (argc > --j && j >= 0)
		{
			if (tmp == ft_number(argv[j]))
				exit_error("Error\n");
		}
	}
}
