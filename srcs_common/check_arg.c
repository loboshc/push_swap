/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:37:14 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/27 17:47:42 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	select_color(char *instruc, int i, int len, int num)
{
	if (instruc[0] == 's' && (i == 0 || i == 1))
		printf(" \033[32m%d\033[0m", num);
	else if (instruc[0] == 'r' && instruc[1] != 'r' && i == len - 1)
		printf(" \033[32m%d\033[0m", num);
	else if (instruc[0] == 'r' && instruc[1] == 'r' && i == 0)
		printf(" \033[32m%d\033[0m", num);
	else if (instruc[0] == 'p' && i == 0)
		printf(" \033[32m%d\033[0m", num);
	else
		printf(" %d", num);
}

size_t	ft_strlen(const char *s)
{
	unsigned long	i;
	const char		*cad;

	i = 0;
	cad = s;
	while (cad[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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

void	check_arg(int argc, char **argv, int flag)
{
	int	i;
	int	tmp;
	int	j;
	int	x;

	if (flag > 0)
		x = 1;
	else
		x = 0;
	i = x;
	argv++;
	while (i < (argc - 1))
	{
		if ((*argv[i] == '-' || *argv[i] == '+') && argv[i][1] == '\0')
			exit_error("Error\n");
		tmp = ft_number(argv[i]);
		j = i - 1;
		while (argc > j && j >= x)
		{
			if (tmp == ft_number(argv[j]))
				exit_error("Error\n");
			j--;
		}
		i++;
	}
}
