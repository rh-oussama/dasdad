/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oussama <oussama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:31:03 by oussama           #+#    #+#             */
/*   Updated: 2024/03/02 14:48:44 by oussama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hello.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int check_exist_parenthese(char *str);
int close_pair(char *str, int i)
{
	int open;
	int close;

	open = 0;
	close = 0;
	while (str && str[i])
	{
		if (str[i] == '(')
			open++;
		else if (str[i] == ')')
			close++;
		if (open == close)
			return (i);
		i++;
	}

	return (-1);
}

char *remove_parenthesis(char *row_data)
{
	char	*data;
	int	i;

	i = 0;
	while (row_data[i] && isspace(row_data[i]))
		i++;
	data = strndup(&row_data[i + 1], close_pair(row_data, i) - i - 1);
	free(row_data);
	return (data);
}

void skip_quotes(char **str)
{
    char quote = **str;
    (*str)++;
    while (**str != quote && **str != '\0')
        (*str)++;
    if (**str == quote)
        (*str)++;
}

int check_parentheses_validity_3(char **str)
{
    int	i;
    char	c;

    i = 0;
    c = **str;
    while (*str && **str == c)
    {
        i++;
        (*str)++;
    }
    (*str)--;
    if (c == '&' && i != 2)
        return (0);
    if (c == '|' && i > 2)
        return (0);
    return (1);
}

int check_parentheses_validity_2(char **str)
{
    while (**str)
    {
        if (**str == '\'' || **str == '\"')
            skip_quotes(str);
        else if (**str == '|' || **str == '&')
        {
            if (check_parentheses_validity_3(str) == 0)
                return (0);
        }
        (*str) ++;
    }
    return (1);
}

int check_parentheses_validity(char *str)
{
    char *str1;
    int open;
    int close;

    str1 = str;
    open = 0;
    close = 0;
    while (*str)
    {
        if (*str == '\'' || *str == '\"')
            skip_quotes(&str);
        else if (*str == '(')
            open++;
        else if (*str == ')')
            close++;
        if (close > open)
            return (0);
        str++;
    }
    if (open != close)
        return (0);
    if (check_parentheses_validity_2(&str1) == 0)
        return (0);
    return (1);
}

void	check_quotes_validity_2(char **str, int *sing, int *doub)
{
    char	c;

    c = **str;
    if (c == '\'')
        (*sing)++;
    else if (c == '\"')
        (*doub)++;
    (*str)++;
    while (**str != '\0')
    {
        if (**str == c)
        {
            if (c == '\'')
                (*sing)++;
            else if (c == '\"')
                (*doub)++;
            (*str)++;
            return ;
        }
        (*str)++;
    }
}

int	check_quotes_validity(char *str)
{
    int	sing;
    int	doub;

    sing = 0;
    doub = 0;
    while (*str)
    {
        if (*str == '\'' || *str == '\"')
            check_quotes_validity_2(&str, &sing, &doub);
        else
            str++;
    }
    if (sing % 2 == 0 && doub % 2 == 0)
        return (1);
    return (0);
}

int	check_syntax_validity(char	*str)
{
    if (!str)
        return (1);
    if (check_quotes_validity(str) == 0)
    {
        printf("ERROR QUOTES\n");
        return (0);
    }
    if (check_parentheses_validity(str) == 0)
    {
        printf("EROOR PARENTHESE\n");
        return (0);
    }
}

char get_type(char *str)
{
    if (strcmp(str, "&&") == 0 || strcmp(str, "||") == 0)
        return ('O');
    else if (check_exist_parenthese(str) == 1)
	 		return ('T');
	else
        return ('C');
}

int check_exist_parenthese(char *str)
{
    while (str && *str)
    {
        if (*str == '(')
            return (1);		
        str++;
    }
    return (0);
}


void create_tree_V2(char *str, t_tree **head)
{
	char **tmp;
	t_tree * head_tmp;
	t_tree *prev = NULL;
	int i;

	tmp = split_and_or(str);

	i = 0;
	while (tmp[i])
	{
		head_tmp = malloc(sizeof(t_tree));
		if (*head == NULL)
			*head = head_tmp;
		else
			prev->row_next = head_tmp;
		head_tmp->str = strdup(tmp[i]);
		head_tmp->type = get_type(tmp[i]);
		head_tmp->row_next = NULL;
		if (check_exist_parenthese(tmp[i]) == 1)
			create_tree_V2(remove_parenthesis(tmp[i]), &(head_tmp->next));
		prev = head_tmp;
		i++;
	}
}

void print_tree(t_tree *node)
{
	node = node->next->next;
   if (node == NULL)
	 	return;
	while (node)
	{
		printf("str: %s\n", node->str);
		printf("type : %c\n", node->type);
		node = node->row_next;
	}
	
}

int main()
{
	t_tree *head = NULL;
	char *str = "((a && b) || (c && hello))";
	create_tree_V2(str, &head);
	print_tree(head);
	return 0;
}