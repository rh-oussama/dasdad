#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "parse.h"
# include "execution.h"
# include "libft.h"
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>


typedef struct s_ptr
{
    int pstatus;
}   t_ptr;

extern t_ptr   ptr;

typedef struct s_aolist
{
    char type;  
}   t_aolist;




void    parse();
int     ft_print_error(char *str, int n);

#endif