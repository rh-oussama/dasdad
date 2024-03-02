#ifndef HELLO_H
# define HELLO_H


#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "string.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>

typedef struct s_tree
{
	char *str;
	char type;

	struct s_tree *next;
	struct s_tree *prev;
	struct s_tree *row_next;
	struct s_tree *row_prev;
	
}	t_tree;


int is_operator(char *data, int index);
char *get_split_line(char *row_data, int *index);
int split_line_len(char *row_data);
int split_and_or_len(char *row_data);
char **split_and_or(char *row_data);

#endif