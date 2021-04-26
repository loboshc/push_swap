#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h> 
# include <limits.h>
# include "common.h"
# include "get_next_line.h"

void	read_and_execute(t_stack **st_a, t_stack **st_b, int flag);
void	check_execute(t_stack **st_a, t_stack **st_b, int flag, char *read);
void	execute_instruction(char *instruc, t_stack **st_a, t_stack **st_b);

#endif