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
t_stack *create_element(int num);
int	add_element(t_stack **stack, int num);
void print_stack(t_stack *stack, char letter);
int	ft_number(const char *n);

#endif