// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   parenthese.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: oussama <oussama@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/02/29 16:40:41 by oussama           #+#    #+#             */
// /*   Updated: 2024/03/02 14:36:56 by oussama          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "hello.h"

// int	close_pair(char *str, int i)
// {
// 	int	open;
// 	int	close;

// 	open = 0;
// 	close = 0;
// 	while (str && str[i])
// 	{
// 		if (str[i] == '(')
// 			open++;
// 		else if (str[i] == ')')
// 			close++;
// 		if (open == close)
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

// void	insert_node(s_pa **head, s_pa *tmp)
// {
// 	s_pa	*t;

// 	t = *head;
// 	if (*head == NULL)
// 	{
// 		*head = tmp;
// 		return ;
// 	}
// 	while (t->next != NULL)
// 		t = t->next;
// 	t->next = tmp;
// }

// s_pa	*pair_parentheses(char *str)
// {
// 	int		i;
// 	s_pa	*head;
// 	s_pa	*tmp;

// 	i = 0;
// 	head = NULL;
// 	while (str[i])
// 	{
// 		if (str[i] == '(')
// 		{
// 			tmp = (s_pa *) malloc(sizeof(s_pa));
// 			tmp->open_index = i;
// 			tmp->close_index = close_pair(str, i);
// 			tmp->str = strndup(str + i + 1, tmp->close_index - i - 1);
// 			tmp->next = NULL;
// 			insert_node(&head, tmp);
// 		}
// 		i++;
// 	}
// 	return (head);
// }

// int check_parenthese_exist(char *str)
// {
// 	while (*str)
// 	{
// 		if (*str == '(')
// 			return (1);
// 		str++;
// 	}
// 	return (0);	
// }

// // int check_syntax_format(char *str)
// // {
// // 	int i;

// // 	i = 0;
	
// // 	while (str[i])
// // 	{
// // 		if (str[i] == '\'' || str[i]  == '\"' || str[i])
		
// // 	}
	
	
// // }

// // int check_syntax_or_and(char	*str)
// // {
// // 	s_pa	*head;
// // 	s_pa	*tmp;
// // 	char	**tmp_split;

// // 	head = pair_parentheses(str);
// // 	tmp = head;
// // 	while (tmp)
// // 	{
// // 		tmp_split = 
			
		
// // 	}
// // }

// int main(void)
// {
// 	char *input;

// 	input = readline("mini $ ");
// 	while (1)
// 	{
// 		s_pa *head = pair_parentheses(input);
// 		s_pa *tmp = head;
// 		while (tmp != NULL)
// 		{
// 			printf("Open index: %d\n", tmp->open_index);
// 			printf("Close index: %d\n", tmp->close_index);
// 			printf("String: %s\n", tmp->str);
// 			printf("+++++\n");
// 			tmp = tmp->next;
// 		}
// 		tmp = head;
// 		while (tmp != NULL)
// 		{
// 			s_pa *next = tmp->next;
// 			free(tmp->str);
// 			free(tmp);
// 			tmp = next;
// 		}
// 		free(input);
// 		input = readline("mini $ ");
// 	}
// 	return (0);
// }
