#include "minishell.h"

t_ptr   ptr;

int main(int argc, char **argv, char **envp)
{
    if (argc > 1)
        return (ft_print_error("", 1));
    parse();
    return (ptr.pstatus);
}