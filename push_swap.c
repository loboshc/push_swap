#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h> 

void	exit_error(char *string)
{
	write(0,string,strlen(string));
	exit(EXIT_FAILURE);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		ft_atoi(const char *n)
{
	long int i[3];

	i[0] = 0;
	i[2] = 0;
	i[1] = 1;
	while (n[i[0]] == 32 || (n[i[0]] >= 9 && n[i[0]] <= 13))
		i[0]++;
	if (n[i[0]] < '0' && n[i[0]] > '9' && n[i[0]] != '-' && n[i[0]] != '+')
		return (0);
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
			return (-1);
		else if (i[2] * i[1] < -2147483648)
			return (0);
	}
	return (i[2] * i[1]);
}


int		ft_number(const char *n)
{
	long int i[3];

	i[0] = 0;
	i[2] = 0;
	i[1] = 1;
	while (n[i[0]] == 32 || (n[i[0]] >= 9 && n[i[0]] <= 13))
		i[0]++;
	if (n[i[0]] == '-')
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
			return (-1);
		else if (i[2] * i[1] < -2147483648)
			return (0);
	}
	if (!isdigit(n[i[0]]) && n[i[0]] != '\0')
		exit_error("Error\n");
	return (i[2] * i[1]);
}


void check_arg(int argc, char *argv[])
{
	int i;
	int negative; // 1 activo - 0 no activo - pasar a estructura

	i = 0;
	argv++;
	while (i < argc)
	{

	}
}

int	main(int argc, char *argv[])
{
	//check_arg(argc, argv);
	argv++;
	printf("%d\n", ft_number(argv[0]));
	printf("%d\n", ft_atoi(argv[0]));

	return (0);
}