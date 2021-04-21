#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h> 
# include <limits.h>

typedef struct s_stack
{
	int	num;
	int pos;
	struct	s_stack	*next;
}t_stack;

void	check_arg(int argc, char **argv);
void	exit_error(char *string);
int	ft_isdigit(int c);
t_stack *create_element(int num);
int	add_element_stack(t_stack **stack, int num);
void print_stack(t_stack *stack, char letter);
void	load_stack(t_stack **stack, int argc, char **argv);
int	stack_len(t_stack *stack);
t_stack	*last_element(t_stack *stack);
int	ft_number(const char *n);
void	sa(t_stack **stack, int call);
void	sb(t_stack **stack, int call);
void	ss(t_stack **stack_a, t_stack **stack_b, int call);
void	pb(t_stack **stack_b, t_stack **stack_a, int call);
void	pa(t_stack **stack_a, t_stack **stack_b, int call);
void	ra(t_stack **stack_a, int call);
void	rb(t_stack **stack_b, int call);
void rr(t_stack **stack_a, t_stack **stack_b, int call);
void	rra(t_stack **stack_a, int call);
void	rrb(t_stack **stack_b, int call);
void rrr(t_stack **stack_a, t_stack ** stack_b, int call);
int	is_sorted(t_stack *stack);
void sort_3(t_stack **st);
int	get_max_pos(t_stack **stack);
int	get_min(t_stack **stack);
void sort_min(t_stack **st_a, t_stack **st_b);
void	long_sort(char **argv, int argc, t_stack **st_a , t_stack **st_b);
int	get_next_line(int fd, char **line);
void	check_arg(int argc, char **argv);
int		ft_isalpha_lower(int c);
int	find_pos(t_stack **st_a, int argc, char **argv);

#endif