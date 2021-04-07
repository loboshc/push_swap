#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h> 

typedef struct s_stack
{
	int num;
	struct s_stack *next;
}t_stack;

void	exit_error(char *string);
int	ft_isdigit(int c);

#endif