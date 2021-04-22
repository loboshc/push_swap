#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h> 
# include <limits.h>
# include "common.h"


void sort_3(t_stack **st);
int	get_max_pos(t_stack **stack);
int	get_min(t_stack **stack);
void sort_min(t_stack **st_a, t_stack **st_b);
void	long_sort(char **argv, int argc, t_stack **st_a , t_stack **st_b);
int	find_pos(t_stack **st_a, int argc, char **argv);
void return_greater_to_a(t_stack **st_a, t_stack **st_b);

#endif