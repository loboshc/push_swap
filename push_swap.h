#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h> 

typedef struct s_stack
{
	int	num;
	struct	s_stack	*next;
}t_stack;

void	exit_error(char *string);
int	ft_isdigit(int c);
t_stack *create_element(int num);
int	add_element_stack(t_stack **stack, int num);
void print_stack(t_stack *stack, char letter);
void	load_stack(t_stack **stack, int argc, char **argv);
int	stack_len(t_stack *stack);
t_stack	*last_element(t_stack *stack);
int	ft_number(const char *n);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack ** stack_b);
int	is_sorted(t_stack *stack);
void sort_3(t_stack **st);

#endif