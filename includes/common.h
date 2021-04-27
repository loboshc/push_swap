#ifndef COMMON_H
# define COMMON_H
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h> 
# include <limits.h>

typedef struct s_stack
{
	int				num;
	int				pos;
	struct s_stack	*next;
}t_stack;

void	check_arg(int argc, char **argv, int flag);
int		ft_number(const char *n);
void	exit_error(char *string);
int		ft_isdigit(int c);
int		is_sorted(t_stack *stack);
int		add_element_stack(t_stack **stack, int num);
void	print_stack(t_stack *stack, char letter, char *instruc, int flag);
void	load_stack(t_stack **stack, int argc, char **argv, int flag);
int		stack_len(t_stack *stack);
t_stack	*last_element(t_stack *stack);
void	sa(t_stack **stack, int call);
void	sb(t_stack **stack, int call);
void	ss(t_stack **stack_a, t_stack **stack_b, int call);
void	pb(t_stack **stack_b, t_stack **stack_a, int call);
void	pa(t_stack **stack_a, t_stack **stack_b, int call);
void	ra(t_stack **stack_a, int call);
void	rb(t_stack **stack_b, int call);
void	rr(t_stack **stack_a, t_stack **stack_b, int call);
void	rra(t_stack **stack_a, int call);
void	rrb(t_stack **stack_b, int call);
void	rrr(t_stack **stack_a, t_stack **stack_b, int call);
void	free_stack(t_stack *stack);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	select_color(char *instruc, int i, int len, int num);

#endif