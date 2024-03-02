#ifndef PARSE_H
# define PARSE_H

#include <stdio.h>

char    **split_and_or(char *row_data);
int     split_and_or_len( char *row_data);
int     check_input(char *row_data);

#endif