#include "minishell.h"

int ft_print_error(char *str, int n)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    write(2, str, i);
    return (n);
}